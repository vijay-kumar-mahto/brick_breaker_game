//
// Created by vijay on 3/13/25.
//

#include "ScreenManager.h"
#include "MenuScreen.h"

/**
 * Constructor for the ScreenManager class.
 *
 * Creates the game window with specified dimensions (800x600) and title "Brick Breaker".
 * Initializes the first screen as a MenuScreen, sets the framerate limit to 60 FPS,
 * and ensures the mouse cursor is visible for menu navigation.
 */
ScreenManager::ScreenManager()
    : window(sf::VideoMode(800, 600), "Brick Breaker", sf::Style::Default)
    , currentScreen(std::make_unique<MenuScreen>(*this)) {
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(true);
}

/**
 * Main game loop that drives the application.
 *
 * Creates a clock to track elapsed time between frames.
 * Runs continuously while the window is open, delegating to the current screen
 * to handle events, update game state, and render content.
 * The deltaTime ensures consistent gameplay regardless of frame rate fluctuations.
 */
void ScreenManager::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        if (currentScreen) {
            currentScreen->handleEvents(window);
            currentScreen->update(deltaTime);
            currentScreen->render(window);
        }
    }
}

/**
 * Changes the active screen.
 * @param newScreen Unique pointer to the screen to switch to
 *
 * Replaces the current screen with the provided new screen.
 * Used for transitions between different game states
 * (e.g., from menu to gameplay, or from gameplay to game over).
 */
void ScreenManager::setScreen(std::unique_ptr<Screen> newScreen) {
    currentScreen = std::move(newScreen);
}

/**
 * Provides access to the game window.
 * @return Reference to the game's render window
 *
 * Allows screens to access the window for rendering and event processing.
 * This avoids duplicating the window reference across multiple classes.
 */
sf::RenderWindow& ScreenManager::getWindow() {
    return window;
}