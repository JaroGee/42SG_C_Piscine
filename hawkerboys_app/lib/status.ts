export const statusOptions = [
  { value: "NEW", label: "New" },
  { value: "IN_REVIEW", label: "In review" },
  { value: "ACCEPTED", label: "Accepted" },
  { value: "ON_HOLD", label: "On hold" },
  { value: "ARCHIVED", label: "Archived" }
] as const;

export type StatusValue = (typeof statusOptions)[number]["value"];
