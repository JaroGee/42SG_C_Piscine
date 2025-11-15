"use client";

import { useFormState } from "react-dom";
import { statusOptions } from "@/lib/status";
import { FormStatus } from "./FormStatus";
import { ActionState, initialActionState } from "@/lib/formState";

type InternalNotesFormProps = {
  action: (state: ActionState, formData: FormData) => Promise<ActionState>;
  currentStatus: string;
  notes?: string | null;
};

export function InternalNotesForm({ action, currentStatus, notes }: InternalNotesFormProps) {
  const [state, formAction] = useFormState<ActionState, FormData>(action, initialActionState);

  return (
    <form action={formAction} noValidate>
      <FormStatus state={state.status} message={state.message} />
      <div>
        <label htmlFor="status">Status</label>
        <select id="status" name="status" defaultValue={currentStatus}>
          {statusOptions.map((option) => (
            <option key={option.value} value={option.value}>
              {option.label}
            </option>
          ))}
        </select>
        {state.fieldErrors?.status ? <p className="form-error">{state.fieldErrors.status}</p> : null}
      </div>
      <div>
        <label htmlFor="internalNotes">Internal notes</label>
        <textarea id="internalNotes" name="internalNotes" defaultValue={notes ?? ""} placeholder="Add context for the team" />
        {state.fieldErrors?.internalNotes ? <p className="form-error">{state.fieldErrors.internalNotes}</p> : null}
      </div>
      <button type="submit" className="button">
        Save changes
      </button>
    </form>
  );
}
