#include "mainwindow.h"
#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"

MainWindow::MainWindow() :
    window(glfwCreateWindow(1280, 720, "Window Title", nullptr, nullptr))
{
    glfwMakeContextCurrent(window.get());
    glfwSwapInterval(1); // Enable vsync
    gl3wInit();
}

void MainWindow::loop()
{
    while (!glfwWindowShouldClose(window.get()))
    {
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Rendering
        int display_w, display_h;
        glfwGetFramebufferSize(window.get(), &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window.get());
    }
}
