//
// Created by vijay on 3/13/25.
//

#include "ResourceManager.h"
#include <iostream>

/**
 * Gets the singleton instance of the ResourceManager.
 * @return Reference to the only instance of ResourceManager
 *
 * Implements the singleton pattern using static local instance to ensure:
 * - Only one instance of ResourceManager exists in the application
 * - The instance is created only when first needed (lazy initialization)
 * - Thread-safe initialization in C++11 and later
 * This provides centralized access to all game resources.
 */
ResourceManager& ResourceManager::getInstance() {
    static ResourceManager instance;
    return instance;
}

/**
 * Loads all game resources from disk into memory.
 *
 * Loads multiple types of resources:
 * - Sound effects (paddle hit, brick break, power-up, etc.)
 * - Fonts for text rendering
 * - Image textures for visual elements
 *
 * Each resource is stored in appropriate containers indexed by name
 * for easy retrieval. Error messages are displayed in the console
 * if any resource fails to load.
 */
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

/**
 * Retrieves a sound buffer by name.
 * @param name The identifier of the sound buffer to retrieve
 * @return Reference to the requested sf::SoundBuffer
 *
 * Provides access to raw sound buffers, which contain audio data.
 * If the requested buffer doesn't exist, it will be default-constructed
 * due to the use of std::map's operator[].
 */
sf::SoundBuffer& ResourceManager::getSoundBuffer(const std::string& name) {
    return soundBuffers[name];
}

/**
 * Retrieves a sound object by name.
 * @param name The identifier of the sound to retrieve
 * @return Reference to the requested sf::Sound
 *
 * Provides access to playable sound objects that are already linked
 * to their corresponding sound buffers. These objects can be used
 * to control playback (play, pause, stop, volume, etc.).
 */
sf::Sound& ResourceManager::getSound(const std::string& name) {
    return sounds[name];
}

/**
 * Retrieves a font by name.
 * @param name The identifier of the font to retrieve
 * @return Reference to the requested sf::Font
 *
 * Provides access to fonts used for text rendering throughout the game.
 * Most commonly used with sf::Text objects to set the typeface of
 * various UI elements.
 */
sf::Font& ResourceManager::getFont(const std::string& name) {
    return fonts[name];
}

/**
 * Retrieves a texture by name.
 * @param name The identifier of the texture to retrieve
 * @return Reference to the requested sf::Texture
 *
 * Provides access to image textures used for sprites and other
 * visual elements in the game. These textures can be applied to
 * sf::Sprite objects or used with other SFML drawing mechanisms.
 */
sf::Texture& ResourceManager::getTexture(const std::string& name) {
    return textures[name];
}