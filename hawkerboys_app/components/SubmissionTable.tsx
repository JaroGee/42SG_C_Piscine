import Link from "next/link";
import { StatusBadge } from "./StatusBadge";

type TableColumn<T> = {
  header: string;
  accessor: (item: T) => React.ReactNode;
};

type SubmissionTableProps<T extends { id: number; status: string; createdAt: string | Date }> = {
  id?: string;
  title: string;
  baseHref: string;
  columns: TableColumn<T>[];
  rows: T[];
  emptyMessage: string;
};

export function SubmissionTable<T extends { id: number; status: string; createdAt: string | Date }>(
  props: SubmissionTableProps<T>
) {
  const { id, title, baseHref, columns, rows, emptyMessage } = props;

  return (
    <section className="section" id={id}>
      <h2 style={{ marginBottom: "1rem" }}>{title}</h2>
      {rows.length === 0 ? (
        <p className="alert">{emptyMessage}</p>
      ) : (
        <div style={{ overflowX: "auto" }}>
          <table className="table">
            <thead>
              <tr>
                {columns.map((column) => (
                  <th key={column.header}>{column.header}</th>
                ))}
                <th>Status</th>
                <th>Submitted</th>
                <th aria-label="Actions" />
              </tr>
            </thead>
            <tbody>
              {rows.map((row) => (
                <tr key={row.id}>
                  {columns.map((column) => (
                    <td key={column.header}>{column.accessor(row)}</td>
                  ))}
                  <td>
                    <StatusBadge status={row.status} />
                  </td>
                  <td>{new Intl.DateTimeFormat("en-SG", { dateStyle: "medium", timeStyle: "short" }).format(new Date(row.createdAt))}</td>
                  <td>
                    <Link href={`${baseHref}/${row.id}`}>View</Link>
                  </td>
                </tr>
              ))}
            </tbody>
          </table>
        </div>
      )}
    </section>
  );
}
