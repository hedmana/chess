#!/bin/sh
REQUIRED_PKG="build-essential cmake"
PKG_OK=$(dpkg-query -W --showformat='${Status}\n' $REQUIRED_PKG|grep "install ok installed")
echo Checking for $REQUIRED_PKG: $PKG_OK
if [ "" = "$PKG_OK" ]; then
  echo "No $REQUIRED_PKG. Setting up $REQUIRED_PKG."
  sudo apt-get --yes install $REQUIRED_PKGS
fi

mkdir build
cmake CMakeLists.txt -B build
cd build
make

echo "LET'S PLAY CHESS!"
./CHESS
cd ..