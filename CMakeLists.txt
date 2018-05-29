project(ecs_box2d)
cmake_minimum_required(VERSION 3.0)

add_definitions(-DIMGUI_USER_CONFIG="imconfig-SFML.h")

set (PKG_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/pkgs/include)
set (IMGUI_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/pkgs/imgui
    ${CMAKE_SOURCE_DIR}/pkgs/imgui-sfml
)

set (SRCS
    src/main.cpp
    src/mainwindow.cpp
)

set (IMGUI_SRCS
    pkgs/imgui/imgui.cpp
    pkgs/imgui/imgui_demo.cpp
    pkgs/imgui/imgui_draw.cpp
    pkgs/imgui-sfml/imgui-SFML.cpp
)

set (IMGUI_LIBS
    sfml-window sfml-graphics sfml-system
)

link_directories(${CMAKE_SOURCE_DIR}/pkgs/lib)

add_executable(ecs_box2d
    ${IMGUI_SRCS}
    ${SRCS}
)
target_include_directories(ecs_box2d PRIVATE ${PKG_INCLUDE_DIR} ${IMGUI_INCLUDE_DIRS})
target_link_libraries(ecs_box2d PRIVATE ${IMGUI_LIBS} opengl32 gdi32 shell32)