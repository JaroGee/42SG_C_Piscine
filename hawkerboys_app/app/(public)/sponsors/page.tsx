import { revalidatePath } from "next/cache";
import { prisma } from "@/lib/prisma";
import { sponsorInterestSchema } from "@/lib/validation";
import { SponsorForm } from "@/components/forms/SponsorForm";
import { ActionState } from "@/lib/formState";

async function submitSponsor(_prevState: ActionState, formData: FormData): Promise<ActionState> {
  "use server";

  const raw = Object.fromEntries(formData.entries());
  const parsed = sponsorInterestSchema.safeParse(raw);
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
    await prisma.sponsorInterest.create({
      data: parsed.data
    });
    revalidatePath("/admin");
    return { status: "success", message: "Thank you for your support. We will contact you soon." };
  } catch (error) {
    console.error(error);
    return { status: "error", message: "We could not save your interest. Please try again." };
  }
}

export default function SponsorsPage() {
  return (
    <div className="section">
      <h1>Support trainees and stalls</h1>
      <p>
        Every dollar helps trainees focus on learning the craft. We work with companies and individuals to sponsor
        stipends, stall equipment and business coaching.
      </p>
      <section className="section">
        <h2>Ways to partner</h2>
        <div className="card">
          <ul>
            <li>Fund trainee stipends during placements.</li>
            <li>Provide grants or loans for stall setup.</li>
            <li>Offer mentorship in business, marketing or operations.</li>
            <li>Host community pop ups to showcase trainees.</li>
          </ul>
        </div>
      </section>
      <section className="section">
        <h2>Register your interest</h2>
        <SponsorForm action={submitSponsor} />
      </section>
    </div>
  );
}
