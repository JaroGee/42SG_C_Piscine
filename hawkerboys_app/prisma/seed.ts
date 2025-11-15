import { prisma } from "../lib/prisma";

async function main() {
  await prisma.traineeApplication.deleteMany();
  await prisma.hawkerPartner.deleteMany();
  await prisma.sponsorInterest.deleteMany();

  await prisma.traineeApplication.createMany({
    data: [
      {
        fullName: "Mohammad Hafiz Bin Salleh",
        preferredName: "Hafiz",
        contactNumber: "+65 8123 4567",
        email: "hafiz@example.com",
        location: "Jurong West",
        availability: "IMMEDIATELY",
        experience: "Worked at a nasi lemak stall for 6 months.",
        motivation: "I want to build a future for my family and own my stall.",
        supportNeeds: "Would like help with budgeting.",
        referralSource: "Yellow Ribbon"
      },
      {
        fullName: "Tan Wei Jie",
        contactNumber: "+65 9876 5432",
        email: "weijie@example.com",
        location: "Bedok",
        availability: "WITHIN_1_MONTH",
        experience: "No prior experience but passionate about cooking.",
        motivation: "Looking for a stable career path.",
        supportNeeds: "",
        referralSource: "Community partner"
      }
    ]
  });

  await prisma.hawkerPartner.createMany({
    data: [
      {
        stallName: "Uncle Lim Chicken Rice",
        contactName: "Lim Boon Teck",
        contactNumber: "+65 8111 2222",
        email: "unclelim@example.com",
        stallLocation: "Maxwell Food Centre",
        partnershipType: "TRAINING",
        cuisineType: "Hainanese chicken rice",
        message: "Happy to host one trainee at a time."
      },
      {
        stallName: "Spice Route Prata",
        contactName: "Suresh Kumar",
        contactNumber: "+65 8555 6666",
        email: "suresh@example.com",
        stallLocation: "Tekka Centre",
        partnershipType: "BOTH",
        cuisineType: "South Indian",
        message: "Can provide weekend shifts first."
      }
    ]
  });

  await prisma.sponsorInterest.createMany({
    data: [
      {
        organisation: "Neighbourhood Trust",
        contactName: "Clara Tan",
        email: "clara@example.com",
        contactNumber: "+65 8999 0000",
        contribution: "TRAINEE_STIPEND",
        message: "Looking to sponsor two trainees this quarter."
      },
      {
        organisation: "Foodie Friends Collective",
        contactName: "Jason Lee",
        email: "jason@example.com",
        contactNumber: "+65 8222 3333",
        contribution: "STALL_SETUP",
        message: "Keen to fund equipment purchases."
      }
    ]
  });
}

main()
  .then(async () => {
    await prisma.$disconnect();
  })
  .catch(async (error) => {
    console.error(error);
    await prisma.$disconnect();
    process.exit(1);
  });
