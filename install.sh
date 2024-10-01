#!/bin/sh

DIR="${PWD}/build"

# Create build path
if [ -d "$DIR" ]; then
  echo "Rebuilding..."
  rm -r build/*
else
  echo "New Build!"
  mkdir build
fi

# Build the program (CMake)
cmake CMakeLists.txt -B build
cd build
make
cd ..

# Run the program
./chess
