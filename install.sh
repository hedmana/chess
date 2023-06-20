#!/bin/sh
DIR="${PWD}/build"
if [ -d "$DIR" ]; then
  echo "Rebuilding..."
  rm -r build/*
else
  echo "New Build!"
  mkdir build
fi

cmake CMakeLists.txt -B build
cd build
make
cd ..

./chess
