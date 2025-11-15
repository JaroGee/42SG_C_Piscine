PRAGMA foreign_keys=OFF;

CREATE TABLE "TraineeApplication" (
  "id" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  "fullName" TEXT NOT NULL,
  "preferredName" TEXT,
  "contactNumber" TEXT NOT NULL,
  "email" TEXT,
  "location" TEXT NOT NULL,
  "availability" TEXT NOT NULL,
  "experience" TEXT,
  "motivation" TEXT NOT NULL,
  "supportNeeds" TEXT,
  "referralSource" TEXT,
  "status" TEXT NOT NULL DEFAULT 'NEW',
  "internalNotes" TEXT,
  "createdAt" DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  "updatedAt" DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE "HawkerPartner" (
  "id" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  "stallName" TEXT NOT NULL,
  "contactName" TEXT NOT NULL,
  "contactNumber" TEXT NOT NULL,
  "email" TEXT NOT NULL,
  "stallLocation" TEXT NOT NULL,
  "partnershipType" TEXT NOT NULL,
  "cuisineType" TEXT,
  "message" TEXT,
  "status" TEXT NOT NULL DEFAULT 'NEW',
  "internalNotes" TEXT,
  "createdAt" DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  "updatedAt" DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE "SponsorInterest" (
  "id" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  "organisation" TEXT NOT NULL,
  "contactName" TEXT NOT NULL,
  "email" TEXT NOT NULL,
  "contactNumber" TEXT,
  "contribution" TEXT NOT NULL,
  "message" TEXT,
  "status" TEXT NOT NULL DEFAULT 'NEW',
  "internalNotes" TEXT,
  "createdAt" DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  "updatedAt" DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE "AdminUser" (
  "id" INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
  "email" TEXT NOT NULL UNIQUE,
  "password" TEXT NOT NULL,
  "createdAt" DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

PRAGMA foreign_keys=ON;
