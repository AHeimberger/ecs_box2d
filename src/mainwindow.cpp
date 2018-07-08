#include "mainwindow.h"
#include "events.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "systems/bodysystem.h"
#include "systems/box2dsystem.h"
#include "systems/rendersystem.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

MainWindow::MainWindow(const std::experimental::filesystem::path& resource_base_path) :
    window(sf::VideoMode(1024, 720), "Window Title"),
    view(window.getDefaultView()),
    ecs(),
    resourceManager(ecs),
    showBox2dDebug(false)
{
    window.setFramerateLimit(60);
    view.zoom(0.5f);
    view.move(-100.0f, 0);
    window.setView(view);
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

        static bool imguiShowBox2dDebug = showBox2dDebug;
        {
            ImGui::Begin("Game Menu");

            static float f = 0.0f;
            static int counter = 0;
            ImGui::Checkbox("Show Box2D Debug output", &imguiShowBox2dDebug);

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

        if (imguiShowBox2dDebug!=showBox2dDebug) {
            ecs.events.emit<ChangeBox2dDebugOutput>(imguiShowBox2dDebug);
            showBox2dDebug = imguiShowBox2dDebug;
        }

        render(dt.asSeconds());
    }

    ImGui::SFML::Shutdown();
}

void MainWindow::createSystems()
{
    ecs.systems.add<BodySystem>();
    ecs.systems.add<Box2dSystem>(window);
    ecs.systems.add<RenderSystem>(window);
    ecs.systems.configure();
}

void MainWindow::render(entityx::TimeDelta dt)
{
    window.clear();
    ecs.systems.update_all(dt);
    ImGui::SFML::Render(window);
    window.display();
}