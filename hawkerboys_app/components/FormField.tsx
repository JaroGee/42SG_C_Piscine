"use client";

import { useId } from "react";

type FormFieldProps = {
  label: string;
  name: string;
  type?: "text" | "email" | "tel" | "select" | "textarea";
  options?: { value: string; label: string }[];
  defaultValue?: string;
  error?: string;
  required?: boolean;
  placeholder?: string;
};

export function FormField({
  label,
  name,
  type = "text",
  options,
  defaultValue,
  error,
  required,
  placeholder
}: FormFieldProps) {
  const id = useId();

  return (
    <div>
      <label htmlFor={`${id}-${name}`}>
        {label}
        {required ? " *" : ""}
      </label>
      {type === "textarea" ? (
        <textarea id={`${id}-${name}`} name={name} defaultValue={defaultValue} placeholder={placeholder} />
      ) : type === "select" && options ? (
        <select id={`${id}-${name}`} name={name} defaultValue={defaultValue ?? ""}>
          <option value="" disabled>
            Select an option
          </option>
          {options.map((option) => (
            <option key={option.value} value={option.value}>
              {option.label}
            </option>
          ))}
        </select>
      ) : (
        <input id={`${id}-${name}`} name={name} type={type} defaultValue={defaultValue} placeholder={placeholder} />
      )}
      {error ? <p className="form-error" role="alert">{error}</p> : null}
    </div>
  );
}
