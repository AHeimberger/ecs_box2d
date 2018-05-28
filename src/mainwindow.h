#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <memory>

class MainWindow {
public:
    MainWindow();

    void loop();

private:
    struct DestroyGlfwWin {
        void operator()(GLFWwindow* ptr) {
            glfwDestroyWindow(ptr);
        }
    };

    std::unique_ptr<GLFWwindow, DestroyGlfwWin> window;
};

#endif