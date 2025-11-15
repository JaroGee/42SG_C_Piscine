import Link from "next/link";
import { redirect } from "next/navigation";
import { prisma } from "@/lib/prisma";
import { getSession, destroySession } from "@/lib/session";
import { SubmissionTable } from "@/components/SubmissionTable";

async function signOut() {
  "use server";
  await destroySession();
  redirect("/admin/login");
}

export default async function AdminDashboardPage() {
  const session = await getSession();
  if (!session) {
    redirect("/admin/login");
  }

  const [trainees, hawkers, sponsors] = await Promise.all([
    prisma.traineeApplication.findMany({ orderBy: { createdAt: "desc" } }),
    prisma.hawkerPartner.findMany({ orderBy: { createdAt: "desc" } }),
    prisma.sponsorInterest.findMany({ orderBy: { createdAt: "desc" } })
  ]);

  return (
    <div>
      <div className="admin-layout">
        <aside>
          <div className="card" style={{ marginBottom: "1.5rem" }}>
            <p style={{ margin: 0, fontWeight: 600 }}>Signed in as {session.email}</p>
          </div>
          <nav className="admin-nav" aria-label="Admin sections">
            <Link href="#trainees">Trainee applications</Link>
            <Link href="#hawkers">Hawker partners</Link>
            <Link href="#sponsors">Sponsor interest</Link>
          </nav>
          <form action={signOut} style={{ marginTop: "1.5rem" }}>
            <button type="submit" className="button" style={{ width: "100%", background: "#991b1b" }}>
              Sign out
            </button>
          </form>
        </aside>
        <section>
          <SubmissionTable
            id="trainees"
            title="Trainee applications"
            baseHref="/admin/trainees"
            columns={[
              { header: "Name", accessor: (row) => row.fullName },
              { header: "Mobile", accessor: (row) => row.contactNumber },
              { header: "Location", accessor: (row) => row.location }
            ]}
            rows={trainees}
            emptyMessage="No trainee applications yet."
          />
          <SubmissionTable
            id="hawkers"
            title="Hawker partners"
            baseHref="/admin/hawkers"
            columns={[
              { header: "Stall", accessor: (row) => row.stallName },
              { header: "Contact", accessor: (row) => row.contactName },
              { header: "Phone", accessor: (row) => row.contactNumber }
            ]}
            rows={hawkers}
            emptyMessage="No hawker partner submissions yet."
          />
          <SubmissionTable
            id="sponsors"
            title="Sponsors"
            baseHref="/admin/sponsors"
            columns={[
              { header: "Organisation", accessor: (row) => row.organisation },
              { header: "Contact", accessor: (row) => row.contactName },
              { header: "Email", accessor: (row) => row.email }
            ]}
            rows={sponsors}
            emptyMessage="No sponsor interest submissions yet."
          />
        </section>
      </div>
    </div>
  );
}
