# CHESS BOARD (WORK IN PROGRESS)
As a chess enthusiastic BioIT student I naturally have to have a home-made chess board to practice my openings on. I wanted to expand my knowledge in C++ and the SFML library so i took this as an opportunity to do exactly that. The result is an SFML based GUI application in the shape of an interactive chess board. Hit me up if you are looking for an opponent :sunglasses:	

## Build instructions (for Linux)
The project is built using CMake. Included is a shell script (install.sh) that makes sure that all required packages are installed, handles the building process, and spits out a binary executable file for running the program. To build and run the program, navigate to the project root directory and execute the following commands in the terminal:
```
./install.sh
./chess
```
If ure using WSL you'll have to setup an XServer to run a GUI application. Here's a quick guide on how to do it with VcXsrv: https://gist.github.com/djfdyuruiry/3150b9e5f3dadba89ea323df49ea7ab1.
