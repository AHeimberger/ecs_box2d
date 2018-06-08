project(ecs_box2d)
cmake_minimum_required(VERSION 3.0)

configure_file(
    ${CMAKE_SOURCE_DIR}/resources/modular_ships.png
    ${CMAKE_BINARY_DIR}/resources/modular_ships.png 
    COPYONLY
)
configure_file(
    ${CMAKE_SOURCE_DIR}/resources/resources.json
    ${CMAKE_BINARY_DIR}/resources/resources.json 
    COPYONLY
)


add_subdirectory(pkgs/entityx)

add_definitions(-DIMGUI_USER_CONFIG="imconfig-SFML.h")

set (PKG_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/pkgs/include)
set (JSON_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/pkgs/json/include)
set (ENTITYX_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/pkgs/entityx)
set (IMGUI_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/pkgs/imgui
    ${CMAKE_SOURCE_DIR}/pkgs/imgui-sfml
)

set (SRCS
    src/main.cpp
    src/mainwindow.cpp
    src/resourcemanager.cpp

    src/systems/bodysystem.cpp
    src/systems/rendersystem.cpp
)

set (IMGUI_SRCS
    pkgs/imgui/imgui.cpp
    pkgs/imgui/imgui_demo.cpp
    pkgs/imgui/imgui_draw.cpp
    pkgs/imgui-sfml/imgui-SFML.cpp
)

set (ENTITYX_LIBS
    entityx
)

set (IMGUI_LIBS
    sfml-window sfml-graphics sfml-system
)

link_directories(${CMAKE_SOURCE_DIR}/pkgs/lib ${CMAKE_BINARY_DIR}/pkgs/entityx)

add_library(stdc++fs UNKNOWN IMPORTED)
if (MINGW)
    set_property(TARGET stdc++fs PROPERTY IMPORTED_LOCATION "C:/mingw-w64/x86_64-7.3.0-posix-seh-rt_v5-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/7.3.0/libstdc++fs.a")
else (MINGW)
    file(GLOB_RECURSE FILESYSTEM_LIBRARY_PATH /usr/lib/**/libstdc++fs.a)
    set_property(TARGET stdc++fs PROPERTY IMPORTED_LOCATION ${FILESYSTEM_LIBRARY_PATH})
endif (MINGW)

add_executable(ecs_box2d
    ${IMGUI_SRCS}
    ${SRCS}
)
target_include_directories(ecs_box2d PRIVATE ${CMAKE_SOURCE_DIR}/src ${JSON_INCLUDE_DIR} ${PKG_INCLUDE_DIR} ${ENTITYX_INCLUDE_DIR} ${IMGUI_INCLUDE_DIRS})
if (WIN32)
    target_link_libraries(ecs_box2d PRIVATE ${ENTITYX_LIBS} ${IMGUI_LIBS} opengl32 gdi32 shell32 stdc++fs)
else (WIN32)
    target_link_libraries(ecs_box2d PRIVATE ${ENTITYX_LIBS} ${IMGUI_LIBS} GL GLU stdc++fs)
endif (WIN32)