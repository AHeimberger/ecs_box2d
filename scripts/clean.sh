#!/bin/bash

ProjectRoot="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && cd .. && pwd )"

rm -rf \
    ${ProjectRoot}/pkgs \
    ${ProjectRoot}/tmp \
    ${ProjectRoot}/CMakeCache.txt \
    ${ProjectRoot}/Makefile \
    ${ProjectRoot}/cmake_install.CMake \
    ${ProjectRoot}/libbox2d.a \
    ${ProjectRoot}/CMakeFiles \
    ${ProjectRoot}/cmake_install.cmake \
    ${ProjectRoot}/core \
    ${ProjectRoot}/ecs_box2d \
    ${ProjectRoot}/imgui.ini
