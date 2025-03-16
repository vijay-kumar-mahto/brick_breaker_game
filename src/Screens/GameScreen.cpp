//
// Created by vijay on 3/13/25.
//

#include "GameScreen.h"
#include "MenuScreen.h"
#include "ResourceManager.h"

/**
 * Constructor for the GameScreen class.
 * @param screenManager Reference to the ScreenManager that handles screen transitions
 *
 * Initializes the game screen with its core components:
 * - gameLogic: The main game mechanics handler with paddle hit sound
 * - hud: The heads-up display for score and game information
 * - menuClickSound: Sound effect for UI interaction
 * All resources are loaded via the ResourceManager singleton.
 */
GameScreen::GameScreen(ScreenManager& screenManager)
    : screenManager(screenManager)
    , gameLogic(ResourceManager::getInstance().getSound("paddle_hit"))
    , hud()
    , menuClickSound(ResourceManager::getInstance().getSound("menu_click")) {
}

/**
 * Processes user input events.
 * @param window Reference to the game's render window
 *
 * Handles window close events and ESC key press for returning to menu.
 * Delegates HUD-specific event handling to the HUD component.
 * Playing a click sound when navigating back to the menu screen.
 */
void GameScreen::handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            menuClickSound.play();
            screenManager.setScreen(std::make_unique<MenuScreen>(screenManager));
        }
    }
    hud.handleEvents(event, gameLogic, screenManager,menuClickSound);
}

/**
 * Updates game state based on elapsed time.
 * @param deltaTime Time elapsed since the last frame
 *
 * Updates the game logic only if the game is not over.
 * Always updates the HUD with current game statistics from gameLogic.
 */
void GameScreen::update(sf::Time deltaTime) {
    if (!gameLogic.isGameOver()) {
        gameLogic.update(deltaTime, screenManager.getWindow());
    }
    hud.update(gameLogic.getScore(), gameLogic.getLives(), gameLogic.getLevel(), gameLogic); // Updated to pass gameLogic
}

/**
 * Renders the game elements to the screen.
 * @param window Reference to the render window
 *
 * Clears the window with a dark blue background color,
 * renders the game elements (bricks, paddle, ball) via gameLogic,
 * renders the HUD with game information, and displays the result.
 */
void GameScreen::render(sf::RenderWindow& window) {
    window.clear(sf::Color(20, 20, 40));
    gameLogic.render(window);
    hud.render(window, gameLogic.isGameOver());
    window.display();
}

/**
 * Resets the game state.
 * @param newGame Flag indicating if this is a brand new game
 * @param selectedLevel The level to start playing at
 * @param speedMultiplier Factor affecting game speed
 *
 * Delegates to gameLogic to reset the game with the specified parameters.
 * Used when starting a new game, restarting after game over,
 * or when selecting a specific level from the menu.
 */
void GameScreen::resetGame(bool newGame, int selectedLevel, float speedMultiplier) {
    gameLogic.resetGame(newGame, selectedLevel, speedMultiplier);
}