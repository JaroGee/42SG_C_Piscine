import { z } from "zod";

const envSchema = z.object({
  DATABASE_URL: z.string().url(),
  ADMIN_EMAIL: z.string().email(),
  ADMIN_PASSWORD_HASH: z.string().min(20, "Provide a bcrypt hash."),
  SESSION_SECRET: z.string().min(32, "SESSION_SECRET must be at least 32 characters."),
  NODE_ENV: z.enum(["development", "test", "production"]).default("development")
});

type Env = z.infer<typeof envSchema>;

let envCache: Env | null = null;

export function getEnv(): Env {
  if (envCache) {
    return envCache;
  }

  const parsed = envSchema.safeParse({
    DATABASE_URL: process.env.DATABASE_URL,
    ADMIN_EMAIL: process.env.ADMIN_EMAIL,
    ADMIN_PASSWORD_HASH: process.env.ADMIN_PASSWORD_HASH,
    SESSION_SECRET: process.env.SESSION_SECRET,
    NODE_ENV: process.env.NODE_ENV ?? "development"
  });

  if (!parsed.success) {
    const messages = parsed.error.issues
      .map((issue) => `${issue.path.join(".") || ""} ${issue.message}`.trim())
      .join("; ");
    throw new Error(`Invalid environment configuration: ${messages}`);
  }

  envCache = parsed.data;
  return envCache;
}
