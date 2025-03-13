#include "ResourceManager.h"
#include <iostream>

ResourceManager& ResourceManager::getInstance() {
    static ResourceManager instance;
    return instance;
}

void ResourceManager::loadResources() {
    std::vector<std::pair<std::string, std::string>> soundFiles = {
        {"paddle_hit", "Resources/paddle_hit.wav"},
        {"brick_break", "Resources/brick_break.wav"},
        {"power_up", "Resources/power_up.wav"},
        {"life_lost", "Resources/life_lost.wav"},
        {"menu_click", "Resources/menu_click.wav"}
    };

    for (const auto& [name, path] : soundFiles) {
        if (!soundBuffers[name].loadFromFile(path)) {
            std::cout << "Failed to load " << path << "!" << std::endl;
        }
        sounds[name].setBuffer(soundBuffers[name]);
    }

    if (!fonts["default"].loadFromFile("Resources/font.ttf")) {
        std::cout << "Failed to load font.ttf!" << std::endl;
    }

    if (!textures["heart"].loadFromFile("Resources/heart.png")) {
        std::cout << "Failed to load heart.png!" << std::endl;
    }
}

sf::SoundBuffer& ResourceManager::getSoundBuffer(const std::string& name) {
    return soundBuffers[name];
}

sf::Sound& ResourceManager::getSound(const std::string& name) {
    return sounds[name];
}

sf::Font& ResourceManager::getFont(const std::string& name) {
    return fonts[name];
}

sf::Texture& ResourceManager::getTexture(const std::string& name) {
    return textures[name];
}