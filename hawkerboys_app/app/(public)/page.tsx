import Link from "next/link";

const highlights = [
  {
    title: "Pathway to stall ownership",
    copy: "Structured milestones from on-the-job training to stall management with mentorship at every step."
  },
  {
    title: "Support beyond training",
    copy: "Aftercare circles, financial literacy coaching and check-ins that respect each trainee's pace."
  },
  {
    title: "Stronger hawker ecosystem",
    copy: "Partner stalls gain reliable talent and contribute to a fairer food scene in Singapore."
  }
];

export default function LandingPage() {
  return (
    <div className="landing">
      <section className="hero" aria-labelledby="hero-title">
        <h1 id="hero-title">Hawker Boys</h1>
        <p>
          We train and coach ex-offenders to become confident hawkers, pairing them with mentors, partner stalls and
          sponsors who believe in second chances done right.
        </p>
        <div style={{ marginTop: "1.5rem", display: "flex", gap: "1rem", flexWrap: "wrap" }}>
          <Link href="/trainees" className="button">
            Apply as a trainee
          </Link>
          <Link href="/hawkers" className="button" style={{ background: "var(--hb-dark)" }}>
            Partner as a hawker
          </Link>
          <Link href="/sponsors" className="button" style={{ background: "#15803d" }}>
            Support a trainee
          </Link>
        </div>
      </section>

      <section className="section" aria-labelledby="approach-heading">
        <h2 id="approach-heading">What makes our approach different</h2>
        <div className="card-grid">
          {highlights.map((item) => (
            <article key={item.title} className="card">
              <h3>{item.title}</h3>
              <p>{item.copy}</p>
            </article>
          ))}
        </div>
      </section>

      <section className="section" aria-labelledby="journey-heading">
        <h2 id="journey-heading">How the journey works</h2>
        <div className="card">
          <ol style={{ paddingLeft: "1.25rem" }}>
            <li>Intro chat to understand goals and readiness.</li>
            <li>12-week paid placement with a partnering hawker mentor.</li>
            <li>Skills clinics covering finance, menu costing and stall operations.</li>
            <li>Access to savings match programme for stall capital.</li>
            <li>Long term check-ins once the trainee runs their own stall.</li>
          </ol>
        </div>
      </section>
    </div>
  );
}
