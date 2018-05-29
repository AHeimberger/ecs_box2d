#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics/RenderWindow.hpp>

class MainWindow {
public:
    MainWindow();

    void loop();

private:
    sf::RenderWindow window;
};

#endif