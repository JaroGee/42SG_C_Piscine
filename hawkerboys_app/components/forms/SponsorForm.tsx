"use client";

import { useFormState } from "react-dom";
import { FormField } from "@/components/FormField";
import { FormStatus } from "@/components/FormStatus";
import { ActionState, initialActionState } from "@/lib/formState";

const contributionOptions = [
  { value: "TRAINEE_STIPEND", label: "Sponsor trainee stipend" },
  { value: "STALL_SETUP", label: "Sponsor stall set-up" },
  { value: "MENTORSHIP", label: "Offer mentorship or training" },
  { value: "OTHER", label: "Other support" }
];

type SponsorFormProps = {
  action: (state: ActionState, formData: FormData) => Promise<ActionState>;
};

export function SponsorForm({ action }: SponsorFormProps) {
  const [state, formAction] = useFormState<ActionState, FormData>(action, initialActionState);

  return (
    <form action={formAction} noValidate>
      <FormStatus state={state.status} message={state.message} />
      <FormField label="Organisation or name" name="organisation" required error={state.fieldErrors?.organisation} />
      <FormField label="Contact person" name="contactName" required error={state.fieldErrors?.contactName} />
      <FormField label="Email" name="email" type="email" required error={state.fieldErrors?.email} />
      <FormField label="Phone" name="contactNumber" type="tel" placeholder="Optional" error={state.fieldErrors?.contactNumber} />
      <FormField label="How would you like to contribute?" name="contribution" type="select" options={contributionOptions} required error={state.fieldErrors?.contribution} />
      <FormField label="Share any ideas or questions" name="message" type="textarea" placeholder="Optional" error={state.fieldErrors?.message} />
      <button className="button" type="submit">
        Send message
      </button>
    </form>
  );
}
