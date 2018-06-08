Building
========

Building the project should always be possible using CMake. However you first have to
make sure, the prereqps* script for your shell is once successfully run so that all
direct project dependencies are downloaded, built and installed inside the project
directory. Check the respective chapters below to make sure you have all packages
and tools installed to run the prereqps script.

MinGW
-----

Downloaded the toolchain from https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-posix/seh/

Also created an additional mingw-w64.bat called mingw-w64-ps.bat which creates a PowerShell environment (simply replace the last line in the script)

Linux
-----

SFML must most likely be built from scratch due to missing C++11 settings in the prebuilt
SFML libraries. Make sure you have the following packages installed

cmake
libfreetype6-dev
libjpeg-dev
libflac++-dev libflac-dev
libogg-dev
libopenal-dev
libvorbis-dev
libxrandr-dev
