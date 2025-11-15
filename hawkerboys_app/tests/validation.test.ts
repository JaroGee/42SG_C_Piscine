import { describe, expect, it } from "vitest";
import { traineeApplicationSchema, sponsorInterestSchema } from "@/lib/validation";

describe("traineeApplicationSchema", () => {
  it("accepts valid minimal data", () => {
    const result = traineeApplicationSchema.safeParse({
      fullName: "John Doe",
      contactNumber: "81234567",
      email: "",
      location: "Hougang",
      availability: "IMMEDIATELY",
      motivation: "I want to learn to run a stall."
    });
    expect(result.success).toBe(true);
  });

  it("fails when required fields are missing", () => {
    const result = traineeApplicationSchema.safeParse({});
    expect(result.success).toBe(false);
  });
});

describe("sponsorInterestSchema", () => {
  it("requires contact information", () => {
    const result = sponsorInterestSchema.safeParse({
      organisation: "Company",
      contactName: "Jane",
      email: "jane@example.com",
      contribution: "TRAINEE_STIPEND"
    });
    expect(result.success).toBe(true);
  });

  it("rejects invalid emails", () => {
    const result = sponsorInterestSchema.safeParse({
      organisation: "Company",
      contactName: "Jane",
      email: "not-an-email",
      contribution: "TRAINEE_STIPEND"
    });
    expect(result.success).toBe(false);
  });
});
