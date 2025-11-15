import Link from "next/link";

export default function PublicLayout({
  children
}: {
  children: React.ReactNode;
}) {
  return (
    <>
      <header>
        <div className="container">
          <nav className="navbar" aria-label="Main navigation">
            <Link href="/" className="button" style={{ background: "transparent", color: "var(--hb-dark)", padding: 0 }}>
              <span style={{ fontSize: "1.5rem", fontWeight: 700 }}>Hawker Boys</span>
            </Link>
            <div className="nav-links">
              <Link href="/trainees">For Trainees</Link>
              <Link href="/hawkers">For Hawkers</Link>
              <Link href="/sponsors">For Sponsors</Link>
              <Link href="/admin/login">Admin</Link>
            </div>
          </nav>
        </div>
      </header>
      <main>
        <div className="container">{children}</div>
      </main>
      <footer>
        <div className="container">
          <small>&copy; {new Date().getFullYear()} Hawker Boys. Training ex-offenders towards stall ownership.</small>
        </div>
      </footer>
    </>
  );
}
