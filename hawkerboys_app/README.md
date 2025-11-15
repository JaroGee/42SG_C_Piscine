# Hawker Boys app

A Next.js app that supports the Hawker Boys programme with public information pages and a simple admin dashboard to review trainee, hawker and sponsor submissions.

## Prerequisites

- macOS with Apple Silicon (tested on M2)
- Node.js 20 (install via [fnm](https://github.com/Schniz/fnm) or `brew install node`)
- npm 10 (bundled with Node 20)

Enable corepack if you prefer pnpm or yarn, but all commands below use npm.

```zsh
corepack enable # optional
```

## Environment variables

Copy the sample file and populate the values.

```zsh
cd hawkerboys_app
cp -n .env.example .env
```

- `DATABASE_URL`: Leave as the default `file:./prisma/dev.db` for local SQLite usage.
- `ADMIN_EMAIL`: Email used for admin login.
- `ADMIN_PASSWORD_HASH`: Bcrypt hash of the admin password. Generate one with:
  ```zsh
  node -e "console.log(require('bcryptjs').hashSync('your-password', 10))"
  ```
- `SESSION_SECRET`: Long random string (minimum 32 characters). You can generate one with `openssl rand -base64 32`.

## Installation

```zsh
cd hawkerboys_app
npm install
```

## Database setup

Push the Prisma schema and apply the initial migration. The command creates the SQLite database file under `prisma/dev.db`.

```zsh
npm run db:migrate -- --name init
```

Generate the Prisma client (this also happens automatically during `npm install`).

```zsh
npm run prisma:generate
```

Seed the database with sample trainee, hawker and sponsor records.

```zsh
npm run db:seed
```

## Development

```zsh
npm run dev
```

The app runs at http://localhost:3000. Public forms are open to everyone. The admin dashboard is under `/admin` and requires the credentials defined in `.env`.

## Testing and quality

- Static analysis: `npm run lint`
- Schema sanity checks: `npm run test` (Vitest covers the core validation rules)

Run them together after pulling changes:

```zsh
npm run lint
npm run test
```

## Building for production

```zsh
npm run build
```

The build output lives in `.next`. Start the production server with `npm run start`.

## Deployment notes

- The app works on Vercel, Render or any Node 20 host.
- Set the same environment variables (`DATABASE_URL`, `ADMIN_EMAIL`, `ADMIN_PASSWORD_HASH`, `SESSION_SECRET`).
- For managed Postgres, update `DATABASE_URL` accordingly and run `npm run db:migrate` during deployment.

## Manual QA checklist

1. Submit each public form and confirm a success message appears.
2. Log in at `/admin` using the configured credentials.
3. Confirm the new submissions appear in their respective tables.
4. Open a record, change the status and save notes. Reload to confirm persistence.
5. Log out and ensure the session is cleared.

## Known follow-ups

- Add pagination and filters for larger submission volumes.
- Allow admins to export submissions as CSV.
- Introduce email notifications to admins upon new submissions.
