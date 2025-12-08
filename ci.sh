#!/usr/bin/env bash
set -e

# Create build directory
mkdir -p build

# Change into the build directory
cd build

# Configure the project using CMake
cmake ..

# Build the project
cmake --build .

# Run tests using CTest
ctest

# Go back to the project root and ensure this script is executable (if not already)
cd ..
chmod +x ci.sh
