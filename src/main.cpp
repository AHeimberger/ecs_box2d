#include "mainwindow.h"
#include <experimental/filesystem>

int main(int, char* argv[])
{
    std::experimental::filesystem::path executable_path(argv[0]);
    MainWindow mainWindow{executable_path.parent_path() / "resources"};
    mainWindow.loop();

    return 0;
}