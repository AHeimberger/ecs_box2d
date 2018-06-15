#include "resourcemanager.h"
#include "components/body.h"
#include "components/physics.h"
#include "components/renderable.h"
#include <nlohmann/json.hpp>
#include <fstream>

using nlohmann::json;

ResourceManager::ResourceManager(entityx::EntityX& ecs) :
    ecs(ecs),
    textures()
{
}

void ResourceManager::loadScene(std::experimental::filesystem::path resource_base_path)
{
    std::ifstream resource_config_file((resource_base_path / "resources.json").string());
    json resources;
    resource_config_file >> resources;

    for (json::iterator it = resources["Textures"].begin();
         it != resources["Textures"].end();
         ++it)
    {
        textures[it.key()].loadFromFile((resource_base_path / it.value().get<std::string>()).string());
    }

    for (auto& entity_config : resources["Entities"])
    {
        entityx::Entity entity = ecs.entities.create();
        if (entity_config.find("Position")!=entity_config.end())
        {
            sf::Vector2f position(entity_config["Position"]["x"], entity_config["Position"]["y"]);
            sf::Vector2f speed(entity_config["Speed"]["vx"], entity_config["Speed"]["vy"]);
            entity.assign<Body>(position, speed, 0.0);
        }
        if (entity_config.find("Renderable")!=entity_config.end())
        {
            std::string texture_name = entity_config["Renderable"]["Texture"];
            int x = entity_config["Renderable"]["Sprite"]["x"];
            int y = entity_config["Renderable"]["Sprite"]["y"];
            int w = entity_config["Renderable"]["Sprite"]["w"];
            int h = entity_config["Renderable"]["Sprite"]["h"];
            Renderable image(new sf::Sprite(textures[texture_name], sf::IntRect(x, y, w, h)));
            image->scale(4.0, 4.0);
            entity.assign<Renderable>(image);
        }
        if (entity_config.find("Physics")!=entity_config.end())
        {
            std::string body_type = entity_config["Physics"]["type"];
            if ((body_type!="static") && (body_type!="dynamic"))
            {
                throw std::invalid_argument("Physics.type must either be 'dynamic' or 'static'");
            }
            float initial_x = entity_config["Physics"]["x"];
            float initial_y = entity_config["Physics"]["y"];
            float width = entity_config["Physics"]["width"];
            float height = entity_config["Physics"]["height"];
            entity.assign<Physics>(nullptr,
                    initial_x,
                    initial_y,
                    width,
                    height,
                    body_type=="dynamic" ? BodyType::Dynamic : BodyType::Static);
        }
    }
}