"use client";

import Link from "next/link";
import { useFormState } from "react-dom";
import { FormStatus } from "@/components/FormStatus";
import { ActionState, initialActionState } from "@/lib/formState";

type AdminLoginFormProps = {
  action: (state: ActionState, formData: FormData) => Promise<ActionState>;
};

export function AdminLoginForm({ action }: AdminLoginFormProps) {
  const [state, formAction] = useFormState<ActionState, FormData>(action, initialActionState);

  return (
    <form action={formAction} noValidate style={{ maxWidth: "420px" }}>
      <h1>Admin login</h1>
      <p style={{ marginBottom: "1.5rem" }}>For Hawker Boys staff. Contact the tech lead if you need access.</p>
      <FormStatus state={state.status} message={state.message} />
      <div>
        <label htmlFor="email">Email</label>
        <input id="email" name="email" type="email" required autoComplete="email" />
      </div>
      <div>
        <label htmlFor="password">Password</label>
        <input id="password" name="password" type="password" required autoComplete="current-password" />
      </div>
      <button type="submit" className="button" style={{ width: "100%" }}>
        Sign in
      </button>
      <p style={{ marginTop: "1rem" }}>
        <Link href="/">Back to public site</Link>
      </p>
    </form>
  );
}
