"use client";

import { useEffect, useState } from "react";

type FormStatusProps = {
  state: "idle" | "success" | "error";
  message?: string;
};

export function FormStatus({ state, message }: FormStatusProps) {
  const [visible, setVisible] = useState(state !== "idle");

  useEffect(() => {
    setVisible(state !== "idle");
  }, [state]);

  if (!visible) {
    return null;
  }

  const background = state === "success" ? "rgba(21, 128, 61, 0.15)" : "rgba(185, 28, 28, 0.15)";
  const color = state === "success" ? "#166534" : "#7f1d1d";

  return (
    <p className="alert" style={{ background, color }} role={state === "error" ? "alert" : "status"}>
      {message ?? (state === "success" ? "Thanks for submitting." : "Something went wrong. Please try again.")}
    </p>
  );
}
