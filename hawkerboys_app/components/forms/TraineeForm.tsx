"use client";

import { useFormState } from "react-dom";
import { FormField } from "@/components/FormField";
import { FormStatus } from "@/components/FormStatus";
import { ActionState, initialActionState } from "@/lib/formState";

const availabilityOptions = [
  { value: "IMMEDIATELY", label: "Ready now" },
  { value: "WITHIN_1_MONTH", label: "Within 1 month" },
  { value: "WITHIN_3_MONTHS", label: "Within 3 months" }
];

type TraineeFormProps = {
  action: (state: ActionState, formData: FormData) => Promise<ActionState>;
};

export function TraineeForm({ action }: TraineeFormProps) {
  const [state, formAction] = useFormState<ActionState, FormData>(action, initialActionState);

  return (
    <form action={formAction} noValidate>
      <FormStatus state={state.status} message={state.message} />
      <FormField label="Full name" name="fullName" required error={state.fieldErrors?.fullName} />
      <FormField label="Preferred name" name="preferredName" placeholder="Optional" error={state.fieldErrors?.preferredName} />
      <FormField label="Mobile number" name="contactNumber" type="tel" required error={state.fieldErrors?.contactNumber} />
      <FormField label="Email" name="email" type="email" placeholder="We use this for updates" error={state.fieldErrors?.email} />
      <FormField label="Where are you based?" name="location" required error={state.fieldErrors?.location} />
      <FormField label="When can you start?" name="availability" type="select" options={availabilityOptions} required error={state.fieldErrors?.availability} />
      <FormField label="Tell us about any kitchen experience" name="experience" type="textarea" placeholder="Optional" error={state.fieldErrors?.experience} />
      <FormField label="What draws you to Hawker Boys?" name="motivation" type="textarea" required error={state.fieldErrors?.motivation} />
      <FormField label="Do you need any support from us?" name="supportNeeds" type="textarea" placeholder="Optional" error={state.fieldErrors?.supportNeeds} />
      <FormField label="Who referred you?" name="referralSource" placeholder="Optional" error={state.fieldErrors?.referralSource} />
      <button className="button" type="submit">
        Submit application
      </button>
    </form>
  );
}
