import { statusOptions } from "@/lib/status";

type StatusBadgeProps = {
  status: string;
};

export function StatusBadge({ status }: StatusBadgeProps) {
  const label = statusOptions.find((option) => option.value === status)?.label ?? status;
  return <span className="status-pill">{label}</span>;
}
