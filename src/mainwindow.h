#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <entityx/entityx.h>
#include <experimental/filesystem>

class MainWindow {
public:
    explicit MainWindow(const std::experimental::filesystem::path& resource_base_path);

    void loop();

private:
    void createSystems();
    void setupGame();
    void render(entityx::TimeDelta dt);

private:
    std::experimental::filesystem::path resource_base_path;
    sf::Texture resourceTexture;
    sf::RenderWindow window;
    entityx::EventManager eventManager;
    entityx::EntityManager entityManager;
    entityx::SystemManager systemManager;

};

#endif