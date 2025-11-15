import { revalidatePath } from "next/cache";
import { prisma } from "@/lib/prisma";
import { hawkerPartnerSchema } from "@/lib/validation";
import { HawkerForm } from "@/components/forms/HawkerForm";
import { ActionState } from "@/lib/formState";

async function submitHawker(_prevState: ActionState, formData: FormData): Promise<ActionState> {
  "use server";

  const raw = Object.fromEntries(formData.entries());
  const parsed = hawkerPartnerSchema.safeParse(raw);
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
    await prisma.hawkerPartner.create({
      data: parsed.data
    });
    revalidatePath("/admin");
    return { status: "success", message: "Thank you. We will be in touch within 3 working days." };
  } catch (error) {
    console.error(error);
    return { status: "error", message: "We could not save your interest. Please try again." };
  }
}

export default function HawkersPage() {
  return (
    <div className="section">
      <h1>Partner as a hawker mentor</h1>
      <p>
        We are looking for patient stall owners who can guide trainees on real shifts. We handle matching, admin and
        aftercare so you can focus on the craft.
      </p>
      <section className="section">
        <h2>What we offer</h2>
        <div className="card">
          <ul>
            <li>Trainees paid by Hawker Boys during placements.</li>
            <li>On-site coaching visits from our team.</li>
            <li>Clear expectations and communication tools.</li>
            <li>Option to hire graduates after the placement.</li>
          </ul>
        </div>
      </section>
      <section className="section">
        <h2>Register your interest</h2>
        <HawkerForm action={submitHawker} />
      </section>
    </div>
  );
}
