import { notFound, redirect } from "next/navigation";
import Link from "next/link";
import { revalidatePath } from "next/cache";
import { prisma } from "@/lib/prisma";
import { getSession } from "@/lib/session";
import { internalUpdateSchema } from "@/lib/validation";
import { InternalNotesForm } from "@/components/InternalNotesForm";
import { StatusBadge } from "@/components/StatusBadge";
import { ActionState } from "@/lib/formState";

async function updateSponsor(id: number, _prev: ActionState, formData: FormData): Promise<ActionState> {
  "use server";

  const session = await getSession();
  if (!session) {
    redirect("/admin/login");
  }

  const parsed = internalUpdateSchema.safeParse(Object.fromEntries(formData.entries()));
  if (!parsed.success) {
    const fieldErrors: Record<string, string> = {};
    for (const issue of parsed.error.issues) {
      const [field] = issue.path;
      if (field) {
        fieldErrors[field as string] = issue.message;
      }
    }
    return { status: "error", message: "Please fix the highlighted fields.", fieldErrors };
  }

  try {
    await prisma.sponsorInterest.update({
      where: { id },
      data: {
        status: parsed.data.status,
        internalNotes: parsed.data.internalNotes ?? null
      }
    });
    revalidatePath(`/admin/sponsors/${id}`);
    revalidatePath("/admin");
    return { status: "success", message: "Saved." };
  } catch (error) {
    console.error(error);
    return { status: "error", message: "Unable to save changes." };
  }
}

export default async function SponsorDetail({ params }: { params: { id: string } }) {
  const session = await getSession();
  if (!session) {
    redirect("/admin/login");
  }

  const sponsor = await prisma.sponsorInterest.findUnique({ where: { id: Number(params.id) } });
  if (!sponsor) {
    notFound();
  }

  return (
    <div className="section">
      <Link href="/admin">← Back to admin</Link>
      <header style={{ marginTop: "1.5rem", marginBottom: "1.5rem" }}>
        <h1 style={{ marginBottom: "0.5rem" }}>{sponsor.organisation}</h1>
        <StatusBadge status={sponsor.status} />
        <p style={{ marginTop: "0.5rem" }}>
          Submitted {new Intl.DateTimeFormat("en-SG", { dateStyle: "medium", timeStyle: "short" }).format(sponsor.createdAt)}
        </p>
      </header>
      <section className="section">
        <h2>Contact details</h2>
        <div className="card">
          <dl style={{ display: "grid", gap: "1rem" }}>
            <div>
              <dt style={{ fontWeight: 600 }}>Contact person</dt>
              <dd style={{ margin: 0 }}>{sponsor.contactName}</dd>
            </div>
            <div>
              <dt style={{ fontWeight: 600 }}>Email</dt>
              <dd style={{ margin: 0 }}>{sponsor.email}</dd>
            </div>
            {sponsor.contactNumber ? (
              <div>
                <dt style={{ fontWeight: 600 }}>Phone</dt>
                <dd style={{ margin: 0 }}>{sponsor.contactNumber}</dd>
              </div>
            ) : null}
            <div>
              <dt style={{ fontWeight: 600 }}>Contribution type</dt>
              <dd style={{ margin: 0 }}>{sponsor.contribution}</dd>
            </div>
            {sponsor.message ? (
              <div>
                <dt style={{ fontWeight: 600 }}>Message</dt>
                <dd style={{ margin: 0 }}>{sponsor.message}</dd>
              </div>
            ) : null}
          </dl>
        </div>
      </section>
      <section className="section">
        <h2>Internal updates</h2>
        <InternalNotesForm
          action={updateSponsor.bind(null, sponsor.id)}
          currentStatus={sponsor.status}
          notes={sponsor.internalNotes}
        />
      </section>
    </div>
  );
}
