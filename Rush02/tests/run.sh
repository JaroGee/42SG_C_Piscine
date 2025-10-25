#!/bin/bash
set -e

echo "🔨 Building..."
make re

echo "🧩 BASIC CHECKS"
./rush-02 0
./rush-02 5
./rush-02 13
./rush-02 20
./rush-02 100
./rush-02 1000
./rush-02 1234567
./rush-02 1000001
./rush-02 1000000000

echo "✅ Done!"