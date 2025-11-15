import { cookies } from "next/headers";
import { SignJWT, jwtVerify } from "jose";
import { getEnv } from "./env";

const SESSION_COOKIE = "hawkerboys_admin";
const SESSION_DURATION_MS = 1000 * 60 * 60 * 12; // 12 hours

type SessionPayload = {
  sub: string;
  email: string;
};

export async function createSession(email: string) {
  const { SESSION_SECRET } = getEnv();
  const secret = new TextEncoder().encode(SESSION_SECRET);
  const token = await new SignJWT({ email })
    .setProtectedHeader({ alg: "HS256" })
    .setIssuedAt()
    .setSubject(email)
    .setExpirationTime(Math.floor((Date.now() + SESSION_DURATION_MS) / 1000))
    .sign(secret);

  const cookieStore = await cookies();
  cookieStore.set(SESSION_COOKIE, token, {
    httpOnly: true,
    sameSite: "lax",
    secure: process.env.NODE_ENV === "production",
    maxAge: SESSION_DURATION_MS / 1000,
    path: "/"
  });
}

export async function getSession(): Promise<SessionPayload | null> {
  const cookieStore = await cookies();
  const token = cookieStore.get(SESSION_COOKIE)?.value;
  if (!token) {
    return null;
  }

  try {
    const { SESSION_SECRET } = getEnv();
    const secret = new TextEncoder().encode(SESSION_SECRET);
    const { payload } = await jwtVerify<SessionPayload>(token, secret);
    return { sub: payload.sub ?? "", email: payload.email };
  } catch (error) {
    await destroySession();
    return null;
  }
}

export async function requireSession() {
  const session = await getSession();
  if (!session) {
    throw new Error("UNAUTHENTICATED");
  }
  return session;
}

export async function destroySession() {
  const cookieStore = await cookies();
  cookieStore.set(SESSION_COOKIE, "", {
    httpOnly: true,
    sameSite: "lax",
    secure: process.env.NODE_ENV === "production",
    maxAge: 0,
    path: "/"
  });
}
