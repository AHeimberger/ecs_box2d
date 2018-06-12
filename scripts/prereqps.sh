#!/bin/bash

ProjectRoot="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && cd .. && pwd )"

mkdir -p ${ProjectRoot}/pkgs
mkdir -p ${ProjectRoot}/tmp

pushd ${ProjectRoot}/pkgs
if [ ! -d ${ProjectRoot}/pkgs/imgui ]; then
    echo "Cloning ImGUI"
    git clone https://github.com/ocornut/imgui.git
fi
if [ ! -d ${ProjectRoot}/pkgs/imgui-sfml ]; then
    echo "Cloning ImGUI-SFML"
    git clone https://github.com/eliasdaler/imgui-sfml.git
fi
if [ ! -d ${ProjectRoot}/pkgs/entityx ]; then
    echo "Cloning EntityX"
    git clone https://github.com/alecthomas/entityx.git
fi
if [ ! -d ${ProjectRoot}/pkgs/json ]; then
    echo "Cloning nlohmann::json"
    git clone https://github.com/nlohmann/json.git
fi
if [ ! -d ${ProjectRoot}/pkgs/Box2D ]; then
    echo "Cloning Box2D"
    git clone https://github.com/erincatto/Box2D.git
fi
popd

if [ ! -d ${ProjectRoot}/pkgs/include/SFML ]; then
    echo "Downloading and creating SFML"
    wget https://www.sfml-dev.org/files/SFML-2.5.0-sources.zip -O ${ProjectRoot}/tmp/SFML-2.5.0-src.zip
    unzip -q ${ProjectRoot}/tmp/SFML-2.5.0-src.zip -d ${ProjectRoot}/tmp/
    pushd ${ProjectRoot}/tmp/SFML-2.5.0
    mkdir build
    cd build
    cmake -DCMAKE_INSTALL_PREFIX=${ProjectRoot}/pkgs ..
    cmake --build .
    cmake --build . --target install
    popd
fi