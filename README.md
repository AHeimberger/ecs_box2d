# ECS-Box2D

This is an experiment to create an EntityX- and SFML-based game that includes lots of
other interesting game-related libraries like Box2d, ImGui, a scripting language etc.

## Getting Started

This is a CMake/C++-based project that should be compilable under Linux and Windows. It
features a bash-script and a Powershell script to fetch, install and, where necessary,
build required prerequisites of the project. So far it was tested using a MinGW
compiler for Windows as specified below and using GCC for Linux. Other compilers might
work as well however.

### MinGW Environment

Install a CMake version at least version 3.10 As for the compiler, I'm successfully
using this one for my development:
https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-posix/seh/

Once you have all the tools installed, run this command from the source root in a
powershell:

```
.\scripts\prereqps.ps1
```

After that you additionally might want to create an `env.ps1` similar to the
following to simplify the setup of the build environment later:

```
$env:PATH=$env:PATH+";c:\projects\ecs_box2d\pkgs\bin"
$env:PATH=$env:PATH+";c:\projects\ecs_box2d\build_mingw\pkgs\entityx"
$env:PATH=$env:PATH+";c:\Program Files\CMake\bin\"
```

### Linux Environment

For Linux, SFML has to be built from source to include the C++11 settings. This
is done for you in the prerequisites script. But you still need to install the
following packages:

```
sudo apt-get install \
    cmake \
    libfreetype6-dev \
    libjpeg-dev \
    libflac++-dev libflac-dev \
    libogg-dev \
    libopenal-dev \
    libvorbis-dev \
    libxrandr-dev
```

## Building

Once everything is set up you can just run these steps from the root directory of the
sources using a powershell or bash:

```
mkdir build
cd build
cmake ..
cmake --build .
```

### Using Docker

If you like docker, just change your current directory within the terminal into the cloned directory
and run the whole script from bellow.


```
# well some variables
CLONED_DIR="$(pwd)"
DOCKER_TAG_NAME=ecsbox2d

# use docker to build
docker rmi $(docker images -f dangling=true -q)
docker build \
    --build-arg USER_NAME=${USER} \
    --build-arg USER_ID=$(id -u ${USER}) \
    --build-arg GROUP_ID=$(id -g ${USER}) \
    -t ${DOCKER_TAG_NAME} .
docker run --rm=true \
    -e DISPLAY=${DISPLAY} \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v ${CLONED_DIR}/:/project/ \
    -it ${DOCKER_TAG_NAME} /bin/bash

# run some scripts
./scripts/clean.sh
./scripts/prereqps.sh

# build project
cmake .
make

# run program
./ecs_box2d

```
