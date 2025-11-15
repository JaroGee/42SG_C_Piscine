/** @type {import('next').NextConfig} */
const nextConfig = {
  experimental: {
    serverActions: {
      allowedOrigins: ["*"],
      bodySizeLimit: "1mb"
    }
  }
};

export default nextConfig;
