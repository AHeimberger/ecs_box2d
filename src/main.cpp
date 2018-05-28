#include "glfw++.h"
#include "mainwindow.h"

int main(int, char* argv[])
{
    GlfwPlusPlus glfw;

    MainWindow mainWindow;
    mainWindow.loop();

    return 0;
}