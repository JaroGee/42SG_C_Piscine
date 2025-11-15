import { revalidatePath } from "next/cache";
import { prisma } from "@/lib/prisma";
import { traineeApplicationSchema } from "@/lib/validation";
import { TraineeForm } from "@/components/forms/TraineeForm";
import { ActionState } from "@/lib/formState";

async function submitTraineeApplication(_prevState: ActionState, formData: FormData): Promise<ActionState> {
  "use server";

  const raw = Object.fromEntries(formData.entries());
  const parsed = traineeApplicationSchema.safeParse({
    ...raw,
    email: (raw.email as string | undefined) ?? "",
    preferredName: (raw.preferredName as string | undefined) ?? undefined,
    experience: (raw.experience as string | undefined) ?? undefined,
    supportNeeds: (raw.supportNeeds as string | undefined) ?? undefined,
    referralSource: (raw.referralSource as string | undefined) ?? undefined
  });

  if (!parsed.success) {
    const fieldErrors: Record<string, string> = {};
    for (const issue of parsed.error.issues) {
      const [field] = issue.path;
      if (field) {
        fieldErrors[field as string] = issue.message;
      }
    }
    return { status: "error", message: "Please check the highlighted fields.", fieldErrors };
  }

  try {
    await prisma.traineeApplication.create({
      data: {
        ...parsed.data,
        email: parsed.data.email || undefined
      }
    });
    revalidatePath("/admin");
    return { status: "success", message: "Thanks for reaching out. We will contact you within 5 working days." };
  } catch (error) {
    console.error(error);
    return { status: "error", message: "We could not save your application. Please try again." };
  }
}

export default function TraineesPage() {
  return (
    <div className="section">
      <h1>Train with Hawker Boys</h1>
      <p>
        We work with men who are ready to build a steady future through hawker work. Training is paid and includes
        practical support beyond the kitchen.
      </p>
      <section className="section">
        <h2>What to expect</h2>
        <div className="card">
          <ul>
            <li>Paid placement with a patient mentor hawker.</li>
            <li>Coaching on menu costing, service and stall management.</li>
            <li>Weekly aftercare catch ups and goal tracking.</li>
            <li>Support to save toward your own stall.</li>
          </ul>
        </div>
      </section>
      <section className="section">
        <h2>Apply now</h2>
        <TraineeForm action={submitTraineeApplication} />
      </section>
    </div>
  );
}
