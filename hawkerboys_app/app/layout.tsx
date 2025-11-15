import type { Metadata } from "next";
import "./globals.css";

export const metadata: Metadata = {
  title: "Hawker Boys",
  description: "Training ex-offenders towards running their own hawker stalls"
};

export default function RootLayout({
  children
}: {
  children: React.ReactNode;
}) {
  return (
    <html lang="en">
      <body>
        <div className="app-shell">
          {children}
        </div>
      </body>
    </html>
  );
}
