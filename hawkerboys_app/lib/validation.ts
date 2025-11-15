import { z } from "zod";

export const traineeApplicationSchema = z.object({
  fullName: z.string().min(1, "Please share your full name."),
  preferredName: z.string().optional(),
  contactNumber: z.string().min(8, "Add a contact number."),
  email: z.string().email("Enter a valid email.").optional().or(z.literal("")),
  location: z.string().min(1, "Let us know where you are based."),
  availability: z.string().min(1, "Select an availability."),
  experience: z.string().optional(),
  motivation: z.string().min(10, "Tell us a little about why you want to train."),
  supportNeeds: z.string().optional(),
  referralSource: z.string().optional()
});

export type TraineeApplicationInput = z.infer<typeof traineeApplicationSchema>;

export const hawkerPartnerSchema = z.object({
  stallName: z.string().min(1, "Your stall name is required."),
  contactName: z.string().min(1, "Contact person name is required."),
  contactNumber: z.string().min(8, "Share a contact number."),
  email: z.string().email("Enter a valid email."),
  stallLocation: z.string().min(1, "Where is the stall located?"),
  partnershipType: z.string().min(1, "Select at least one option."),
  cuisineType: z.string().optional(),
  message: z.string().optional()
});

export type HawkerPartnerInput = z.infer<typeof hawkerPartnerSchema>;

export const sponsorInterestSchema = z.object({
  organisation: z.string().min(1, "Organisation or name is required."),
  contactName: z.string().min(1, "Contact person name is required."),
  email: z.string().email("Enter a valid email."),
  contactNumber: z.string().optional(),
  contribution: z.string().min(1, "Choose one."),
  message: z.string().optional()
});

export type SponsorInterestInput = z.infer<typeof sponsorInterestSchema>;

export const adminLoginSchema = z.object({
  email: z.string().email("Use a valid email."),
  password: z.string().min(8, "Password must be at least 8 characters."),
  remember: z.string().optional()
});

export type AdminLoginInput = z.infer<typeof adminLoginSchema>;

export const internalUpdateSchema = z.object({
  status: z
    .string()
    .min(1, "Select a status.")
    .refine((value) => ["NEW", "IN_REVIEW", "ACCEPTED", "ON_HOLD", "ARCHIVED"].includes(value), {
      message: "Invalid status"
    }),
  internalNotes: z.string().optional()
});

export type InternalUpdateInput = z.infer<typeof internalUpdateSchema>;
