"use client";

import { useFormState } from "react-dom";
import { FormField } from "@/components/FormField";
import { FormStatus } from "@/components/FormStatus";
import { ActionState, initialActionState } from "@/lib/formState";

const partnershipOptions = [
  { value: "TRAINING", label: "Training placements" },
  { value: "HIRING", label: "Hiring graduates" },
  { value: "BOTH", label: "Both training and hiring" }
];

type HawkerFormProps = {
  action: (state: ActionState, formData: FormData) => Promise<ActionState>;
};

export function HawkerForm({ action }: HawkerFormProps) {
  const [state, formAction] = useFormState<ActionState, FormData>(action, initialActionState);

  return (
    <form action={formAction} noValidate>
      <FormStatus state={state.status} message={state.message} />
      <FormField label="Stall name" name="stallName" required error={state.fieldErrors?.stallName} />
      <FormField label="Contact person" name="contactName" required error={state.fieldErrors?.contactName} />
      <FormField label="Mobile number" name="contactNumber" type="tel" required error={state.fieldErrors?.contactNumber} />
      <FormField label="Email" name="email" type="email" required error={state.fieldErrors?.email} />
      <FormField label="Stall location" name="stallLocation" required error={state.fieldErrors?.stallLocation} />
      <FormField label="How would you like to work with us?" name="partnershipType" type="select" options={partnershipOptions} required error={state.fieldErrors?.partnershipType} />
      <FormField label="Cuisine type" name="cuisineType" placeholder="Optional" error={state.fieldErrors?.cuisineType} />
      <FormField label="Anything we should know?" name="message" type="textarea" placeholder="Optional" error={state.fieldErrors?.message} />
      <button className="button" type="submit">
        Send interest
      </button>
    </form>
  );
}
