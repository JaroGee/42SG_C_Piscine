import { redirect } from "next/navigation";
import bcrypt from "bcryptjs";
import { adminLoginSchema } from "@/lib/validation";
import { getEnv } from "@/lib/env";
import { createSession, getSession } from "@/lib/session";
import { AdminLoginForm } from "@/components/forms/AdminLoginForm";
import { ActionState } from "@/lib/formState";

async function login(_prevState: ActionState, formData: FormData): Promise<ActionState> {
  "use server";

  const session = await getSession();
  if (session) {
    redirect("/admin");
  }

  const parsed = adminLoginSchema.safeParse(Object.fromEntries(formData.entries()));
  if (!parsed.success) {
    return { status: "error", message: "Please provide a valid email and password." };
  }

  const env = getEnv();
  if (parsed.data.email !== env.ADMIN_EMAIL) {
    return { status: "error", message: "Incorrect email or password." };
  }

  const isValid = await bcrypt.compare(parsed.data.password, env.ADMIN_PASSWORD_HASH);
  if (!isValid) {
    return { status: "error", message: "Incorrect email or password." };
  }

  await createSession(env.ADMIN_EMAIL);
  redirect("/admin");
}

export default async function AdminLoginPage() {
  const session = await getSession();
  if (session) {
    redirect("/admin");
  }

  return (
    <div className="section">
      <AdminLoginForm action={login} />
    </div>
  );
}
