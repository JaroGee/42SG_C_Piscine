import { NextResponse } from "next/server";
import type { NextRequest } from "next/server";
import { jwtVerify } from "jose";

export async function middleware(request: NextRequest) {
  const { pathname } = request.nextUrl;

  if (pathname.startsWith("/admin/login") || pathname.startsWith("/api")) {
    return NextResponse.next();
  }

  const token = request.cookies.get("hawkerboys_admin")?.value;
  if (!token) {
    const loginUrl = new URL("/admin/login", request.url);
    return NextResponse.redirect(loginUrl);
  }

  const secret = process.env.SESSION_SECRET;
  if (!secret) {
    console.error("SESSION_SECRET is missing. Allowing request to avoid lockout.");
    return NextResponse.next();
  }

  try {
    const encodedSecret = new TextEncoder().encode(secret);
    await jwtVerify(token, encodedSecret);
    return NextResponse.next();
  } catch (error) {
    console.warn("Invalid admin session", error);
    const loginUrl = new URL("/admin/login", request.url);
    return NextResponse.redirect(loginUrl);
  }
}

export const config = {
  matcher: ["/admin/:path*"]
};
