#!/bin/bash

ProjectRoot="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && cd .. && pwd )"

mkdir -p ${ProjectRoot}/pkgs
mkdir -p ${ProjectRoot}/tmp

pushd ${ProjectRoot}/pkgs
    if [ ! -d ${ProjectRoot}/pkgs/imgui ]; then
        echo -e "\nCloning ImGUI"
        git clone https://github.com/ocornut/imgui.git --depth 1
    fi
    if [ ! -d ${ProjectRoot}/pkgs/imgui-sfml ]; then
        echo -e "\nCloning ImGUI-SFML"
        git clone https://github.com/eliasdaler/imgui-sfml.git --depth 1
    fi
    if [ ! -d ${ProjectRoot}/pkgs/entityx ]; then
        echo -e "\nCloning EntityX"
        git clone https://github.com/alecthomas/entityx.git --depth 1
    fi
    if [ ! -d ${ProjectRoot}/pkgs/json ]; then
        echo -e "\nCloning nlohmann::json"
        git clone https://github.com/nlohmann/json.git --depth 1
    fi
    if [ ! -d ${ProjectRoot}/pkgs/Box2D ]; then
        echo -e "\nCloning Box2D"
        git clone https://github.com/erincatto/Box2D.git --depth 1
    fi
popd

if [ ! -d ${ProjectRoot}/pkgs/include/SFML ]; then
    echo -e "\nDownloading and creating SFML"
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
