//
// Created by vijay on 3/13/25.
//

#include "MenuScreen.h"
#include "GameScreen.h"
#include "ResourceManager.h"

/**
 * Constructor for the MenuScreen class.
 * @param screenManager Reference to the ScreenManager that handles screen transitions
 *
 * Initializes the menu screen with necessary components:
 * - interface: Handles the visual elements of the menu
 * - records: Manages game statistics and high scores
 * - selectingLevel: Boolean flag for level selection mode
 * - resumeAvailable: Boolean flag indicating if a game can be resumed
 * - menuClickSound: Sound effect for UI interaction
 * - highScore: Current high score loaded from records
 *
 * Also sets up the interface based on the window dimensions.
 */
MenuScreen::MenuScreen(ScreenManager& screenManager)
    : screenManager(screenManager)
    , interface()
    , records()
    , selectingLevel(false)
    , resumeAvailable(false)
    , menuClickSound(ResourceManager::getInstance().getSound("menu_click"))
    , highScore(records.getHighScore()) { // Initialize highScore
    interface.setup(screenManager.getWindow());
}

/**
 * Processes user input events.
 * @param window Reference to the game's render window
 *
 * Handles various input events including:
 * - Window close events
 * - 'N' key press to enter level selection mode
 * - 'R' key press to resume a game if available
 * - Mouse interactions via the interface component
 *
 * Also synchronizes high score resets with the GameRecords system.
 */
void MenuScreen::handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::N && !selectingLevel) {
                menuClickSound.play();
                selectingLevel = true;
            }
            else if (event.key.code == sf::Keyboard::R && resumeAvailable) {
                menuClickSound.play();
                screenManager.setScreen(std::make_unique<GameScreen>(screenManager));
            }
        }
        interface.handleMouseEvents(event, selectingLevel, resumeAvailable, menuClickSound, screenManager, highScore);
        if (highScore == 0) { // Check if reset occurred
            records.resetHighScore(); // Sync reset to GameRecords
        }
    }
}

/**
 * Updates the menu state based on elapsed time.
 * @param deltaTime Time elapsed since the last frame
 *
 * Delegates to the interface component to update animations and visual effects.
 * Passes relevant state information including selectingLevel and resumeAvailable flags,
 * as well as game statistics like highScore.
 */
void MenuScreen::update(sf::Time deltaTime) {
    interface.animate(deltaTime, selectingLevel, resumeAvailable, 0, 3, highScore, 1);
}

/**
 * Renders the menu elements to the screen.
 * @param window Reference to the render window
 *
 * Clears the window with a dark blue background color,
 * renders the menu interface with current state information,
 * and displays the result.
 */
void MenuScreen::render(sf::RenderWindow& window) {
    window.clear(sf::Color(20, 20, 40));
    interface.renderMenu(window, selectingLevel, resumeAvailable, highScore);
    window.display();
}