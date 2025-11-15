import { notFound, redirect } from "next/navigation";
import Link from "next/link";
import { revalidatePath } from "next/cache";
import { prisma } from "@/lib/prisma";
import { getSession } from "@/lib/session";
import { internalUpdateSchema } from "@/lib/validation";
import { InternalNotesForm } from "@/components/InternalNotesForm";
import { StatusBadge } from "@/components/StatusBadge";
import { ActionState } from "@/lib/formState";

async function updateHawker(id: number, _prev: ActionState, formData: FormData): Promise<ActionState> {
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
    await prisma.hawkerPartner.update({
      where: { id },
      data: {
        status: parsed.data.status,
        internalNotes: parsed.data.internalNotes ?? null
      }
    });
    revalidatePath(`/admin/hawkers/${id}`);
    revalidatePath("/admin");
    return { status: "success", message: "Saved." };
  } catch (error) {
    console.error(error);
    return { status: "error", message: "Unable to save changes." };
  }
}

export default async function HawkerDetail({ params }: { params: { id: string } }) {
  const session = await getSession();
  if (!session) {
    redirect("/admin/login");
  }

  const hawker = await prisma.hawkerPartner.findUnique({ where: { id: Number(params.id) } });
  if (!hawker) {
    notFound();
  }

  return (
    <div className="section">
      <Link href="/admin">← Back to admin</Link>
      <header style={{ marginTop: "1.5rem", marginBottom: "1.5rem" }}>
        <h1 style={{ marginBottom: "0.5rem" }}>{hawker.stallName}</h1>
        <StatusBadge status={hawker.status} />
        <p style={{ marginTop: "0.5rem" }}>
          Submitted {new Intl.DateTimeFormat("en-SG", { dateStyle: "medium", timeStyle: "short" }).format(hawker.createdAt)}
        </p>
      </header>
      <section className="section">
        <h2>Partner details</h2>
        <div className="card">
          <dl style={{ display: "grid", gap: "1rem" }}>
            <div>
              <dt style={{ fontWeight: 600 }}>Contact person</dt>
              <dd style={{ margin: 0 }}>{hawker.contactName}</dd>
            </div>
            <div>
              <dt style={{ fontWeight: 600 }}>Contact number</dt>
              <dd style={{ margin: 0 }}>{hawker.contactNumber}</dd>
            </div>
            <div>
              <dt style={{ fontWeight: 600 }}>Email</dt>
              <dd style={{ margin: 0 }}>{hawker.email}</dd>
            </div>
            <div>
              <dt style={{ fontWeight: 600 }}>Stall location</dt>
              <dd style={{ margin: 0 }}>{hawker.stallLocation}</dd>
            </div>
            <div>
              <dt style={{ fontWeight: 600 }}>Partnership interest</dt>
              <dd style={{ margin: 0 }}>{hawker.partnershipType}</dd>
            </div>
            {hawker.cuisineType ? (
              <div>
                <dt style={{ fontWeight: 600 }}>Cuisine</dt>
                <dd style={{ margin: 0 }}>{hawker.cuisineType}</dd>
              </div>
            ) : null}
            {hawker.message ? (
              <div>
                <dt style={{ fontWeight: 600 }}>Message</dt>
                <dd style={{ margin: 0 }}>{hawker.message}</dd>
              </div>
            ) : null}
          </dl>
        </div>
      </section>
      <section className="section">
        <h2>Internal updates</h2>
        <InternalNotesForm
          action={updateHawker.bind(null, hawker.id)}
          currentStatus={hawker.status}
          notes={hawker.internalNotes}
        />
      </section>
    </div>
  );
}
