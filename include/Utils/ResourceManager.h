//
// Created by vijay on 3/13/25.
//

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>

class ResourceManager {
public:
    static ResourceManager& getInstance();
    void loadResources();
    sf::SoundBuffer& getSoundBuffer(const std::string& name);
    sf::Sound& getSound(const std::string& name);
    sf::Font& getFont(const std::string& name);
    sf::Texture& getTexture(const std::string& name);

private:
    ResourceManager() = default;
    std::map<std::string, sf::SoundBuffer> soundBuffers;
    std::map<std::string, sf::Sound> sounds;
    std::map<std::string, sf::Font> fonts;
    std::map<std::string, sf::Texture> textures;
};

#endif