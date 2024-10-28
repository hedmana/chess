# CHESS BOARD 
- Language: C++
- GUI: SFML (https://www.sfml-dev.org/).

![Chess demo](assets/gifs/chess.gif)

## Dependencies
- CMake v3.13.4 &rarr;
- Compiler: GNU v11.4.0
- SFML-2.5.1 (included in the repo)

## Build instructions (Linux)
The project is compiled using CMake. Included is a bash script, ```install.sh```, that handles the build: 

```bash
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

# Execute the program
./chess
```

**NOTE!** If ure using WSL you'll have to setup an XServer to run a GUI application: https://learn.microsoft.com/en-us/windows/wsl/tutorials/gui-apps
