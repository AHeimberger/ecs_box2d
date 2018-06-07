#include "mainwindow.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "systems/bodysystem.h"
#include "systems/rendersystem.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

MainWindow::MainWindow(const std::experimental::filesystem::path& resource_base_path) :
    window(sf::VideoMode(1024, 720), "Window Title"),
    ecs(),
    resourceManager(ecs)
{
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    createSystems();

    resourceManager.loadScene(resource_base_path);
}

void MainWindow::loop()
{
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    sf::Clock deltaClock;

    while (window.isOpen())
    {
        sf::Time dt = deltaClock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, dt);

        {
            ImGui::Begin("Main Menu");

            static float f = 0.0f;
            static int counter = 0;
            ImGui::Text("Hello, world!");                           // Display some text (you can use a format string too)
            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (NB: most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        render(dt.asSeconds());
    }

    ImGui::SFML::Shutdown();
}

void MainWindow::createSystems()
{
    ecs.systems.add<BodySystem>();
    ecs.systems.add<RenderSystem>(window);
}

void MainWindow::render(entityx::TimeDelta dt)
{
    window.clear();
    ecs.systems.update_all(dt);
    ImGui::SFML::Render(window);
    window.display();
}