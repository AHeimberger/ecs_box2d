project(ecs_box2d)
cmake_minimum_required(VERSION 3.0)

set (PKG_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/pkgs/include)
set (IMGUI_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/pkgs/imgui
    ${CMAKE_SOURCE_DIR}/pkgs/imgui/examples/libs/gl3w
    ${CMAKE_SOURCE_DIR}/pkgs/imgui/examples/opengl3_example
)

set (SRCS
    src/glfw++.cpp
    src/main.cpp
    src/mainwindow.cpp
)

set (IMGUI_SRCS
    pkgs/imgui/imgui.cpp
    pkgs/imgui/imgui_demo.cpp
    pkgs/imgui/imgui_draw.cpp
    pkgs/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp
    pkgs/imgui/examples/libs/gl3w/GL/gl3w.c
)

link_directories(${CMAKE_SOURCE_DIR}/pkgs/lib-mingw-w64)

add_executable(ecs_box2d
    ${IMGUI_SRCS}
    ${SRCS}
)
target_include_directories(ecs_box2d PRIVATE ${PKG_INCLUDE_DIR} ${IMGUI_INCLUDE_DIRS})
target_link_libraries(ecs_box2d PRIVATE glfw3 opengl32 gdi32 shell32)