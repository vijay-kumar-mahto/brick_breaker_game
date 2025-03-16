//
// Created by vijay on 3/13/25.
//

#include "HUD.h"
#include "MenuScreen.h"
#include <iostream>

/**
 * Constructor for the HUD (Heads-Up Display) class.
 *
 * Initializes the HUD with default values.
 * Sets the popup state to inactive initially.
 * Likely sets up text elements, fonts, and positions for score, lives,
 * level indicators, and other UI components that will be displayed during gameplay.
 */
HUD::HUD() : isPopupActive(false) {
    if (!font.loadFromFile("Resources/font.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
    }

    uiPanel.setSize(sf::Vector2f(800, 50));
    uiPanel.setFillColor(sf::Color(40, 40, 60, 220));
    uiPanel.setOutlineColor(sf::Color(150, 150, 150));
    uiPanel.setOutlineThickness(1);

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setOutlineColor(sf::Color(0, 0, 0, 150));
    scoreText.setOutlineThickness(1);
    scoreText.setPosition(20, 10);

    highScoreText.setFont(font);
    highScoreText.setCharacterSize(24);
    highScoreText.setFillColor(sf::Color::White);
    highScoreText.setOutlineColor(sf::Color(0, 0, 0, 150));
    highScoreText.setOutlineThickness(1);
    highScoreText.setPosition(200, 10);

    levelText.setFont(font);
    levelText.setCharacterSize(24);
    levelText.setFillColor(sf::Color::White);
    levelText.setOutlineColor(sf::Color(0, 0, 0, 150));
    levelText.setOutlineThickness(1);
    levelText.setPosition(400, 10);

    livesText.setFont(font);
    livesText.setCharacterSize(24);
    livesText.setFillColor(sf::Color::White);
    livesText.setOutlineColor(sf::Color(0, 0, 0, 150));
    livesText.setOutlineThickness(1);
    livesText.setPosition(600, 10);

    buttonPanel.setSize(sf::Vector2f(800, 50));
    buttonPanel.setPosition(0, 50);
    buttonPanel.setFillColor(sf::Color(40, 40, 60, 220));
    buttonPanel.setOutlineColor(sf::Color(150, 150, 150));
    buttonPanel.setOutlineThickness(1);

    pauseResumeButton.setSize(sf::Vector2f(110, 40));
    pauseResumeButton.setPosition(60, 55);
    pauseResumeButton.setFillColor(sf::Color(60, 120, 180));
    pauseResumeButton.setOutlineColor(sf::Color::White);
    pauseResumeButton.setOutlineThickness(2);

    pauseResumeText.setFont(font);
    pauseResumeText.setCharacterSize(24);
    pauseResumeText.setFillColor(sf::Color::White);
    pauseResumeText.setPosition(75, 60);

    exitButton.setSize(sf::Vector2f(80, 40));
    exitButton.setPosition(260, 55);
    exitButton.setFillColor(sf::Color(200, 50, 50));
    exitButton.setOutlineColor(sf::Color::White);
    exitButton.setOutlineThickness(2);

    exitButtonText.setFont(font);
    exitButtonText.setString("Exit");
    exitButtonText.setCharacterSize(20);
    exitButtonText.setFillColor(sf::Color::White);
    exitButtonText.setPosition(280, 63);

    resetButton.setSize(sf::Vector2f(80, 40));
    resetButton.setPosition(460, 55);
    resetButton.setFillColor(sf::Color(50, 200, 50));
    resetButton.setOutlineColor(sf::Color::White);
    resetButton.setOutlineThickness(2);

    resetButtonText.setFont(font);
    resetButtonText.setString("Reset");
    resetButtonText.setCharacterSize(20);
    resetButtonText.setFillColor(sf::Color::White);
    resetButtonText.setPosition(475, 63);

    mainMenuButton.setSize(sf::Vector2f(80, 40));
    mainMenuButton.setPosition(660, 55);
    mainMenuButton.setFillColor(sf::Color(50, 50, 200));
    mainMenuButton.setOutlineColor(sf::Color::White);
    mainMenuButton.setOutlineThickness(2);

    mainMenuButtonText.setFont(font);
    mainMenuButtonText.setString("Menu");
    mainMenuButtonText.setCharacterSize(20);
    mainMenuButtonText.setFillColor(sf::Color::White);
    mainMenuButtonText.setPosition(680, 63);

    popupWindow.setSize(sf::Vector2f(400, 200));
    popupWindow.setPosition(200, 200);
    popupWindow.setFillColor(sf::Color(40, 40, 60, 220));
    popupWindow.setOutlineColor(sf::Color(150, 150, 150));
    popupWindow.setOutlineThickness(2);

    popupTitle.setFont(font);
    popupTitle.setString("Game Over");
    popupTitle.setCharacterSize(30);
    popupTitle.setFillColor(sf::Color::White);
    popupTitle.setPosition(325, 220);

    popupExitButton.setSize(sf::Vector2f(80, 40));
    popupExitButton.setPosition(230, 300);
    popupExitButton.setFillColor(sf::Color(200, 50, 50));
    popupExitButton.setOutlineColor(sf::Color::White);
    popupExitButton.setOutlineThickness(2);

    popupExitButtonText.setFont(font);
    popupExitButtonText.setString("Exit");
    popupExitButtonText.setCharacterSize(20);
    popupExitButtonText.setFillColor(sf::Color::White);
    popupExitButtonText.setPosition(255, 308);

    popupResetButton.setSize(sf::Vector2f(80, 40));
    popupResetButton.setPosition(360, 300);
    popupResetButton.setFillColor(sf::Color(50, 200, 50));
    popupResetButton.setOutlineColor(sf::Color::White);
    popupResetButton.setOutlineThickness(2);

    popupResetButtonText.setFont(font);
    popupResetButtonText.setString("Reset");
    popupResetButtonText.setCharacterSize(20);
    popupResetButtonText.setFillColor(sf::Color::White);
    popupResetButtonText.setPosition(370, 308);

    popupMainMenuButton.setSize(sf::Vector2f(80, 40));
    popupMainMenuButton.setPosition(490, 300);
    popupMainMenuButton.setFillColor(sf::Color(50, 50, 200));
    popupMainMenuButton.setOutlineColor(sf::Color::White);
    popupMainMenuButton.setOutlineThickness(2);

    popupMainMenuButtonText.setFont(font);
    popupMainMenuButtonText.setString("Menu");
    popupMainMenuButtonText.setCharacterSize(20);
    popupMainMenuButtonText.setFillColor(sf::Color::White);
    popupMainMenuButtonText.setPosition(505, 308);
}

/**
 * Processes user input events related to the HUD.
 * @param event Reference to the current SFML event
 * @param gameLogic Reference to the game's logic controller
 * @param screenManager Reference to the screen management system
 * @param menuClickSound Reference to the sound effect for UI interaction
 *
 * Handles user interactions with HUD elements, such as:
 * - Button clicks in game over screens
 * - Popup menu interactions
 * - Pause menu controls
 * - Navigation between different game states via UI
 * Triggers appropriate sound effects and screen transitions based on user input.
 */
void HUD::handleEvents(sf::Event& event, GameLogic& gameLogic, ScreenManager& screenManager, sf::Sound& menuClickSound) {
    if (event.type == sf::Event::MouseMoved) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(screenManager.getWindow());

        // Bar 2 buttons: Only handle hover if popup is not active
        if (!isPopupActive) {
            if (pauseResumeButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                pauseResumeButton.setScale(1.05f, 1.05f);
            else
                pauseResumeButton.setScale(1.0f, 1.0f);
            if (exitButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                exitButton.setScale(1.05f, 1.05f);
            else
                exitButton.setScale(1.0f, 1.0f);
            if (resetButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                resetButton.setScale(1.05f, 1.05f);
            else
                resetButton.setScale(1.0f, 1.0f);
            if (mainMenuButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                mainMenuButton.setScale(1.05f, 1.05f);
            else
                mainMenuButton.setScale(1.0f, 1.0f);
        }

        // Popup buttons: Always handle hover if popup is active
        if (isPopupActive) {
            if (popupExitButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                popupExitButton.setScale(1.05f, 1.05f);
            else
                popupExitButton.setScale(1.0f, 1.0f);
            if (popupResetButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                popupResetButton.setScale(1.05f, 1.05f);
            else
                popupResetButton.setScale(1.0f, 1.0f);
            if (popupMainMenuButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                popupMainMenuButton.setScale(1.05f, 1.05f);
            else
                popupMainMenuButton.setScale(1.0f, 1.0f);
        }
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(screenManager.getWindow());

        // Bar 2 buttons: Only handle clicks if popup is not active
        if (!isPopupActive) {
            if (pauseResumeButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                bool isCurrentlyPaused = gameLogic.isPaused();
                gameLogic.setPaused(!isCurrentlyPaused);
            }
            if (exitButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                screenManager.getWindow().close();
            }
            if (resetButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                gameLogic.resetGame(true);
            }
            if (mainMenuButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                screenManager.setScreen(std::make_unique<MenuScreen>(screenManager));
            }
        }

        // Popup buttons: Always handle clicks if popup is active
        if (isPopupActive) {
            if (popupExitButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                screenManager.getWindow().close();
            }
            if (popupResetButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                gameLogic.resetGame(true);
                isPopupActive = false;
            }
            if (popupMainMenuButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                screenManager.setScreen(std::make_unique<MenuScreen>(screenManager));
                isPopupActive = false;
            }
        }
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && gameLogic.isGameOver()) {
        gameLogic.resetGame(true);
    }
}

/**
 * Updates the HUD's state with current game information.
 * @param score Current player score
 * @param lives Remaining player lives
 * @param level Current game level
 * @param gameLogic Reference to the game's logic controller for additional state information
 *
 * Refreshes all displayed information on the HUD based on the current game state.
 * Updates score counters, life indicators, level displays, and any other
 * dynamic information shown to the player during gameplay.
 * May also handle animations or visual effects for changing values.
 */
void HUD::update(int score, int lives, int level, GameLogic& gameLogic) {
    scoreText.setString("Score: " + std::to_string(score));
    highScoreText.setString("High Score: " + std::to_string(gameLogic.getHighScore()));
    levelText.setString("Level: " + std::to_string(level));
    livesText.setString("Lives: " + std::to_string(lives));
    pauseResumeText.setString(gameLogic.isPaused() ? "Resume" : "Pause");

    if (gameLogic.isGameOver() && !isPopupActive) {
        isPopupActive = true;
    }
}

/**
 * Renders the HUD elements to the screen.
 * @param window Reference to the render window
 * @param isGameOver Boolean indicating if the game is in a "game over" state
 *
 * Draws all HUD components to the provided window.
 * Displays different elements based on the game state:
 * - During active gameplay: score, lives, level indicators
 * - During paused state: pause menu options
 * - During game over: final score, restart options, etc.
 * Ensures all text and UI elements are properly positioned and visible.
 */
void HUD::render(sf::RenderWindow& window, bool isGameOver) {
    window.draw(uiPanel);
    window.draw(scoreText);
    window.draw(highScoreText);
    window.draw(levelText);
    window.draw(livesText);

    window.draw(buttonPanel);
    window.draw(pauseResumeButton);
    window.draw(pauseResumeText);
    window.draw(exitButton);
    window.draw(exitButtonText);
    window.draw(resetButton);
    window.draw(resetButtonText);
    window.draw(mainMenuButton);
    window.draw(mainMenuButtonText);

    // Game Over Popup Window
    if (isPopupActive) {
        window.draw(popupWindow);
        window.draw(popupTitle);
        window.draw(popupExitButton);
        window.draw(popupExitButtonText);
        window.draw(popupResetButton);
        window.draw(popupResetButtonText);
        window.draw(popupMainMenuButton);
        window.draw(popupMainMenuButtonText);
    }
}