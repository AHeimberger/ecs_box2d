#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <entityx/quick.h>
#include <SFML/Graphics/Texture.hpp>
#include <experimental/filesystem>
#include <map>

class ResourceManager
{
public:
    explicit ResourceManager(entityx::EntityX& ecs);

    void loadScene(std::experimental::filesystem::path resource_base_path);

private:
    entityx::EntityX& ecs;
    std::map<std::string, sf::Texture> textures;
};

#endif