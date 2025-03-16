//
// Created by vijay on 3/13/25.
//

#include "ScreenManager.h"
#include "ResourceManager.h"

/**
 * The main entry point of the BrickBreaker game.
 * @return Integer status code (0 for successful execution)
 *
 * Initializes the game application in the following sequence:
 * 1. Loads all game resources (sounds, textures, fonts) through the ResourceManager singleton
 * 2. Creates the ScreenManager which handles different game screens and states
 * 3. Starts the game loop by calling the run method of ScreenManager
 * 4. Returns 0 to indicate successful program execution
 *
 * This minimalist main function delegates most functionality to the ScreenManager,
 * following the principle of separation of concerns.
 */
int main() {
    ResourceManager::getInstance().loadResources(); // Load resources once
    ScreenManager screenManager;
    screenManager.run();
    return 0;
}