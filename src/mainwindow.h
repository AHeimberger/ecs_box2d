#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "resourcemanager.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <entityx/quick.h>
#include <experimental/filesystem>

class MainWindow {
public:
    explicit MainWindow(const std::experimental::filesystem::path& resource_base_path);

    void loop();

private:
    void createSystems();
    void render(entityx::TimeDelta dt);

private:
    sf::RenderWindow window;
    entityx::EntityX ecs;
    ResourceManager resourceManager;

    bool showBox2dDebug;
};

#endif