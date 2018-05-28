#include "Glfw++.h"
//#include "imgui.h"
//#include "imgui_impl_glfw_gl3.h"
#include <GL/gl3w.h>    // This example is using gl3w to access OpenGL functions (because it is small). You may use glew/glad/glLoadGen/etc. whatever already works for you.
#include <GLFW/glfw3.h>
#include <stdio.h>

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Error %d: %s\n", error, description);
}

GlfwPlusPlus::GlfwPlusPlus() {
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return;     // TODO: throw exception
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

GlfwPlusPlus::~GlfwPlusPlus() {
    glfwTerminate();
}