import Link from "next/link";
import { ReactNode } from "react";

export default function AdminLayout({ children }: { children: ReactNode }) {
  return (
    <div className="container">
      <header style={{ marginBottom: "2rem" }}>
        <div className="navbar">
          <Link href="/admin" className="button" style={{ background: "transparent", color: "var(--hb-dark)", padding: 0 }}>
            <span style={{ fontSize: "1.5rem", fontWeight: 700 }}>Hawker Boys Admin</span>
          </Link>
          <Link href="/" style={{ fontWeight: 600 }}>
            View public site
          </Link>
        </div>
      </header>
      {children}
    </div>
  );
}
