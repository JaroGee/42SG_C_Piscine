import { notFound, redirect } from "next/navigation";
import Link from "next/link";
import { revalidatePath } from "next/cache";
import { prisma } from "@/lib/prisma";
import { getSession } from "@/lib/session";
import { internalUpdateSchema } from "@/lib/validation";
import { InternalNotesForm } from "@/components/InternalNotesForm";
import { StatusBadge } from "@/components/StatusBadge";
import { ActionState } from "@/lib/formState";

const fieldLabels: Record<string, string> = {
  preferredName: "Preferred name",
  contactNumber: "Mobile",
  email: "Email",
  location: "Location",
  availability: "Availability",
  experience: "Experience",
  motivation: "Motivation",
  supportNeeds: "Support needs",
  referralSource: "Referral source"
};

async function updateTrainee(id: number, _prevState: ActionState, formData: FormData): Promise<ActionState> {
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
    await prisma.traineeApplication.update({
      where: { id },
      data: {
        status: parsed.data.status,
        internalNotes: parsed.data.internalNotes ?? null
      }
    });
    revalidatePath(`/admin/trainees/${id}`);
    revalidatePath("/admin");
    return { status: "success", message: "Saved." };
  } catch (error) {
    console.error(error);
    return { status: "error", message: "Unable to save changes." };
  }
}

export default async function TraineeDetail({ params }: { params: { id: string } }) {
  const session = await getSession();
  if (!session) {
    redirect("/admin/login");
  }

  const trainee = await prisma.traineeApplication.findUnique({ where: { id: Number(params.id) } });
  if (!trainee) {
    notFound();
  }

  return (
    <div className="section">
      <Link href="/admin">← Back to admin</Link>
      <header style={{ marginTop: "1.5rem", marginBottom: "1.5rem" }}>
        <h1 style={{ marginBottom: "0.5rem" }}>{trainee.fullName}</h1>
        <StatusBadge status={trainee.status} />
        <p style={{ marginTop: "0.5rem" }}>
          Submitted {new Intl.DateTimeFormat("en-SG", { dateStyle: "medium", timeStyle: "short" }).format(trainee.createdAt)}
        </p>
      </header>
      <section className="section">
        <h2>Application details</h2>
        <div className="card">
          <dl style={{ display: "grid", gap: "1rem" }}>
            {Object.entries(fieldLabels).map(([key, label]) => {
              const value = trainee[key as keyof typeof trainee];
              if (!value) {
                return null;
              }
              return (
                <div key={key}>
                  <dt style={{ fontWeight: 600 }}>{label}</dt>
                  <dd style={{ margin: 0 }}>{value as string}</dd>
                </div>
              );
            })}
          </dl>
        </div>
      </section>
      <section className="section">
        <h2>Internal updates</h2>
        <InternalNotesForm
          action={updateTrainee.bind(null, trainee.id)}
          currentStatus={trainee.status}
          notes={trainee.internalNotes}
        />
      </section>
    </div>
  );
}
