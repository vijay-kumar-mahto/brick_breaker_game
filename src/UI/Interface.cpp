//
// Created by vijay on 3/13/25.
//

#include "Interface.h"
#include "GameScreen.h"
#include <cmath>
#include <iostream>
#include "ResourceManager.h" // Added for sound control

/**
 * Constructor for the Interface class.
 *
 * Initializes the menu interface components with default values:
 * - animationTime: Tracks elapsed time for animations
 * - settingsHovered: Tracks if settings button is being hovered over
 * - settingsClicked: Tracks if settings panel is currently open
 * - soundOn: Tracks if sound effects are enabled
 *
 * Likely also sets up UI elements including buttons, text, backgrounds,
 * and loads required fonts and textures for the menu interface.
 */
Interface::Interface() : animationTime(0.0f), settingsHovered(false), settingsClicked(false), soundOn(true) {}

/**
 * Configures the interface based on window properties.
 * @param window Reference to the game's render window
 *
 * Positions UI elements according to the window dimensions.
 * Ensures proper scaling and alignment of menu components.
 * Sets up view boundaries and coordinates for interface elements.
 * Called during initialization to properly configure the interface.
 */
void Interface::setup(sf::RenderWindow& window) {
    if (!font.loadFromFile("Resources/font.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
    }

    // Main Menu Setup
    menuPanel.setSize(sf::Vector2f(600, 400));
    menuPanel.setPosition(100, 100);
    menuPanel.setFillColor(sf::Color(40, 80, 120));
    menuPanel.setOutlineColor(sf::Color(200, 200, 200));
    menuPanel.setOutlineThickness(2);

    titleText.setFont(font);
    titleText.setString("Brick Breaker");
    titleText.setCharacterSize(60);
    titleText.setFillColor(sf::Color::White);
    titleText.setOutlineColor(sf::Color(0, 0, 0, 150));
    titleText.setOutlineThickness(2);
    titleText.setPosition(220, 120);

    newGameButton.setSize(sf::Vector2f(230, 60));
    newGameButton.setPosition(300, 250);
    newGameButton.setFillColor(sf::Color(60, 120, 180));
    newGameButton.setOutlineColor(sf::Color::White);
    newGameButton.setOutlineThickness(2);

    newGameText.setFont(font);
    newGameText.setString("New Game (N)");
    newGameText.setCharacterSize(24);
    newGameText.setFillColor(sf::Color::White);
    newGameText.setPosition(320, 260);

    resumeGameButton.setSize(sf::Vector2f(230, 60));
    resumeGameButton.setPosition(300, 340);
    resumeGameButton.setFillColor(sf::Color(60, 120, 180));
    resumeGameButton.setOutlineColor(sf::Color::White);
    resumeGameButton.setOutlineThickness(2);

    resumeGameText.setFont(font);
    resumeGameText.setString("Resume Game (R)");
    resumeGameText.setCharacterSize(24);
    resumeGameText.setFillColor(sf::Color::White);
    resumeGameText.setPosition(310, 350);

    shadow.setSize(sf::Vector2f(620, 420));
    shadow.setPosition(110, 110);
    shadow.setFillColor(sf::Color(0, 0, 0, 80));

    highScoreText.setFont(font);
    highScoreText.setCharacterSize(24);
    highScoreText.setFillColor(sf::Color::Yellow);
    highScoreText.setOutlineColor(sf::Color(0, 0, 0, 150));
    highScoreText.setOutlineThickness(1);
    highScoreText.setPosition(150, 10);

    // Level Menu Setup
    level1Button.setSize(sf::Vector2f(110, 40));
    level1Button.setPosition(200, 250);
    level1Button.setFillColor(sf::Color(60, 120, 180));
    level1Button.setOutlineColor(sf::Color::White);
    level1Button.setOutlineThickness(2);

    level1Text.setFont(font);
    level1Text.setString("Level 1");
    level1Text.setCharacterSize(20);
    level1Text.setFillColor(sf::Color::White);
    level1Text.setPosition(220, 255);

    level2Button.setSize(sf::Vector2f(110, 40));
    level2Button.setPosition(350, 250);
    level2Button.setFillColor(sf::Color(60, 120, 180));
    level2Button.setOutlineColor(sf::Color::White);
    level2Button.setOutlineThickness(2);

    level2Text.setFont(font);
    level2Text.setString("Level 2");
    level2Text.setCharacterSize(20);
    level2Text.setFillColor(sf::Color::White);
    level2Text.setPosition(370, 255);

    level3Button.setSize(sf::Vector2f(110, 40));
    level3Button.setPosition(500, 250);
    level3Button.setFillColor(sf::Color(60, 120, 180));
    level3Button.setOutlineColor(sf::Color::White);
    level3Button.setOutlineThickness(2);

    level3Text.setFont(font);
    level3Text.setString("Level 3");
    level3Text.setCharacterSize(20);
    level3Text.setFillColor(sf::Color::White);
    level3Text.setPosition(520, 255);

    // Setup for settings icon (gear) - Static with rectangular teeth
    settingsIconOuter.setRadius(25);
    settingsIconOuter.setPointCount(40); // Smooth outline
    settingsIconOuter.setPosition(750, 50); // Top-right corner
    settingsIconOuter.setFillColor(sf::Color::Transparent); // Hollow
    settingsIconOuter.setOutlineColor(sf::Color::White); // White outline to match menu theme
    settingsIconOuter.setOutlineThickness(1);
    settingsIconOuter.setOrigin(25, 25);

    settingsIconInner.setRadius(12);
    settingsIconInner.setPointCount(40);
    settingsIconInner.setPosition(750, 50);
    settingsIconInner.setFillColor(sf::Color::Transparent); // Hollow center
    settingsIconInner.setOutlineColor(sf::Color::White); // White outline
    settingsIconInner.setOutlineThickness(14);
    settingsIconInner.setOrigin(12, 12);

    // Create 8 rectangular gear teeth
    for (int i = 0; i < 8; ++i) {
        settingsIconTeeth[i].setSize(sf::Vector2f(8, 12)); // Rectangular teeth
        float angle = i * 45 * 3.14159f / 180.f; // 45 degrees apart
        settingsIconTeeth[i].setPosition(
            750 + 25 * std::cos(angle), // Position at outer edge
            50 + 25 * std::sin(angle)
        );
        settingsIconTeeth[i].setFillColor(sf::Color::White); // Filled white
        settingsIconTeeth[i].setOutlineColor(sf::Color::White); // White outline
        settingsIconTeeth[i].setOutlineThickness(1);
        settingsIconTeeth[i].setOrigin(0, 6);
        settingsIconTeeth[i].setRotation(i * 45);
    }

    // Setup for settings buttons on menuPanel
    settingText.setFont(font);
    settingText.setString("Setting");
    settingText.setCharacterSize(40);
    settingText.setFillColor(sf::Color::White);
    settingText.setOutlineColor(sf::Color(0, 0, 0, 150));
    settingText.setOutlineThickness(2);
    settingText.setPosition(335, 225);

    soundButton.setSize(sf::Vector2f(200, 50));
    soundButton.setPosition(300, 290);
    soundButton.setFillColor(sf::Color(60, 120, 180));
    soundButton.setOutlineColor(sf::Color::White);
    soundButton.setOutlineThickness(2);

    soundButtonText.setFont(font);
    soundButtonText.setString("Sound ON/OFF");
    soundButtonText.setCharacterSize(22);
    soundButtonText.setFillColor(sf::Color::White);
    soundButtonText.setPosition(330, 300);

    speedButton.setSize(sf::Vector2f(200, 50));
    speedButton.setPosition(300, 360);
    speedButton.setFillColor(sf::Color(60, 120, 180));
    speedButton.setOutlineColor(sf::Color::White);
    speedButton.setOutlineThickness(2);

    speedButtonText.setFont(font);
    speedButtonText.setString("Speed X.Xx");
    speedButtonText.setCharacterSize(22);
    speedButtonText.setFillColor(sf::Color::White);
    speedButtonText.setPosition(340, 370);

    resetHighScoreButton.setSize(sf::Vector2f(200, 50));
    resetHighScoreButton.setPosition(300, 430);
    resetHighScoreButton.setFillColor(sf::Color(60, 120, 180));
    resetHighScoreButton.setOutlineColor(sf::Color::White);
    resetHighScoreButton.setOutlineThickness(2);

    resetHighScoreButtonText.setFont(font);
    resetHighScoreButtonText.setString("Reset High Score");
    resetHighScoreButtonText.setCharacterSize(22);
    resetHighScoreButtonText.setFillColor(sf::Color::White);
    resetHighScoreButtonText.setPosition(310, 440);
}

/**
 * Processes mouse interactions with the interface.
 * @param event Reference to the current SFML event
 * @param selectingLevel Reference to boolean indicating if level selection mode is active
 * @param resumeAvailable Boolean indicating if game resume option should be available
 * @param menuClickSound Reference to the sound effect for UI interaction
 * @param screenManager Reference to the screen management system
 * @param highScore Reference to the current high score value
 *
 * Handles mouse clicks, hovers, and movements over menu elements.
 * Triggers appropriate actions based on which buttons are interacted with:
 * - New game/level selection
 * - Game resuming
 * - Settings changes
 * - High score resets
 * Updates state variables and plays sound effects accordingly.
 */
void Interface::handleMouseEvents(sf::Event& event, bool& selectingLevel, bool resumeAvailable, sf::Sound& menuClickSound, ScreenManager& screenManager, int& highScore) {
    if (event.type == sf::Event::MouseMoved) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(screenManager.getWindow());
        if (newGameButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            newGameButton.setScale(1.05f, 1.05f);
        else
            newGameButton.setScale(1.0f, 1.0f);
        if (resumeGameButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            resumeGameButton.setScale(1.05f, 1.05f);
        else
            resumeGameButton.setScale(1.0f, 1.0f);
        if (level1Button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            level1Button.setScale(1.05f, 1.05f);
        else
            level1Button.setScale(1.0f, 1.0f);
        if (level2Button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            level2Button.setScale(1.05f, 1.05f);
        else
            level2Button.setScale(1.0f, 1.0f);
        if (level3Button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            level3Button.setScale(1.05f, 1.05f);
        else
            level3Button.setScale(1.0f, 1.0f);

        // Handle hover for settings icon
        if (settingsIconOuter.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            settingsHovered = true;
            settingsIconOuter.setScale(1.1f, 1.1f);
            settingsIconInner.setScale(1.1f, 1.1f);
            for (int i = 0; i < 8; ++i) {
                settingsIconTeeth[i].setScale(1.1f, 1.1f);
            }
        } else {
            settingsHovered = false;
            settingsIconOuter.setScale(1.0f, 1.0f);
            settingsIconInner.setScale(1.0f, 1.0f);
            for (int i = 0; i < 8; ++i) {
                settingsIconTeeth[i].setScale(1.0f, 1.0f);
            }
        }

        // Handle hover for settings buttons (only if settingsClicked is true)
        if (settingsClicked) {
            if (soundButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                soundButton.setScale(1.05f, 1.05f);
            else
                soundButton.setScale(1.0f, 1.0f);
            if (speedButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                speedButton.setScale(1.05f, 1.05f);
            else
                speedButton.setScale(1.0f, 1.0f);
            if (resetHighScoreButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
                resetHighScoreButton.setScale(1.05f, 1.05f);
            else
                resetHighScoreButton.setScale(1.0f, 1.0f);
        }
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(screenManager.getWindow());
        // Handle settings icon click as a toggle
        if (settingsIconOuter.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            menuClickSound.play();
            settingsClicked = !settingsClicked; // Toggle settings view
        }
        if (settingsClicked) {
            // Added logic for sound button toggle
            if (soundButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                soundOn = !soundOn; // Toggle sound state
                if (soundOn) {
                    soundButtonText.setString("Sound ON");
                    ResourceManager::getInstance().getSound("paddle_hit").setVolume(100.f);
                    ResourceManager::getInstance().getSound("brick_break").setVolume(100.f);
                    ResourceManager::getInstance().getSound("power_up").setVolume(100.f);
                    ResourceManager::getInstance().getSound("life_lost").setVolume(100.f);
                    ResourceManager::getInstance().getSound("menu_click").setVolume(100.f);
                } else {
                    soundButtonText.setString("Sound OFF");
                    ResourceManager::getInstance().getSound("paddle_hit").setVolume(0.f);
                    ResourceManager::getInstance().getSound("brick_break").setVolume(0.f);
                    ResourceManager::getInstance().getSound("power_up").setVolume(0.f);
                    ResourceManager::getInstance().getSound("life_lost").setVolume(0.f);
                    ResourceManager::getInstance().getSound("menu_click").setVolume(0.f);
                }
            }
            // Speed toggle button GUI change
            if (speedButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                speedState = (speedState + 1) % 4; // Cycle through 0, 1, 2, 3
                switch (speedState) {
                    case 0:
                        speedButtonText.setString("Speed 0.5x");
                    break;
                    case 1:
                        speedButtonText.setString("Speed 1.0x");
                    break;
                    case 2:
                        speedButtonText.setString("Speed 1.5x");
                    break;
                    case 3:
                        speedButtonText.setString("Speed 2.0x");
                    break;
                }
            }
            // Added logic for reset high score button
            if (resetHighScoreButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                highScore = 0; // Reset the actual highScore passed by reference
                highScoreText.setString("High Score: " + std::to_string(highScore)); // Update display
            }
        }
        else {
            if (!selectingLevel) {
                if (newGameButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    menuClickSound.play();
                    selectingLevel = true;
                }
                else if (resumeGameButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    menuClickSound.play();
                    screenManager.setScreen(std::make_unique<GameScreen>(screenManager));
                }
            }
            else {
                if (level1Button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    menuClickSound.play();
                    auto gameScreen = std::make_unique<GameScreen>(screenManager);
                    gameScreen->resetGame(true, 1, getSpeedMultiplier());
                    screenManager.setScreen(std::move(gameScreen));
                }
                else if (level2Button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    menuClickSound.play();
                    auto gameScreen = std::make_unique<GameScreen>(screenManager);
                    gameScreen->resetGame(true, 2, getSpeedMultiplier());
                    screenManager.setScreen(std::move(gameScreen));
                }
                else if (level3Button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    menuClickSound.play();
                    auto gameScreen = std::make_unique<GameScreen>(screenManager);
                    gameScreen->resetGame(true, 3, getSpeedMultiplier());
                    screenManager.setScreen(std::move(gameScreen));
                }
            }
        }
    }
}

/**
 * Updates the interface animations and state over time.
 * @param deltaTime Time elapsed since the last frame
 * @param selectingLevel Boolean indicating if level selection mode is active
 * @param resumeAvailable Boolean indicating if game resume option is available
 * @param score Current player score
 * @param lives Remaining player lives
 * @param highScore Reference to the current high score value
 * @param level Current game level
 *
 * Progresses animations based on elapsed time.
 * Updates visual effects, transitions, and UI element states.
 * May update displayed statistics if they've changed.
 * Controls timing for any menu transitions or effects.
 */
void Interface::animate(sf::Time deltaTime, bool selectingLevel, bool resumeAvailable, int score, int lives, int& highScore, int level) {
    animationTime += deltaTime.asSeconds();
    float pulse = 0.5f + 0.5f * std::sin(animationTime * 2.0f);

    titleText.setScale(1.0f + 0.03f * pulse, 1.0f + 0.03f * pulse);
    sf::Color buttonColor = newGameButton.getFillColor();
    buttonColor.a = static_cast<sf::Uint8>(200 + 55 * pulse);
    newGameButton.setFillColor(buttonColor);
    resumeGameButton.setFillColor(resumeAvailable ? buttonColor : sf::Color(60, 120, 180, 100));
    level1Button.setFillColor(buttonColor);
    level2Button.setFillColor(buttonColor);
    level3Button.setFillColor(buttonColor);

    // Animate settings buttons
    if (settingsClicked) {
        highScoreText.setString("High Score: " + std::to_string(highScore));
        soundButton.setFillColor(buttonColor);
        speedButton.setFillColor(buttonColor);
        resetHighScoreButton.setFillColor(buttonColor);
    }

    highScoreText.setString("High Score: " + std::to_string(highScore));
    // No rotation for settings icon - remains static
}

/**
 * Renders the menu interface to the screen.
 * @param window Reference to the render window
 * @param selectingLevel Boolean indicating if level selection mode is active
 * @param resumeAvailable Boolean indicating if game resume option is available
 * @param highScore Reference to the current high score value
 *
 * Draws all menu components to the provided window:
 * - Title and game logo
 * - Menu buttons (play, resume, settings)
 * - Level selection interface (when active)
 * - High score display
 * - Settings panel (when opened)
 * Ensures all elements are correctly positioned and rendered in proper order.
 */
void Interface::renderMenu(sf::RenderWindow& window, bool selectingLevel, bool resumeAvailable, int& highScore) {
    window.draw(shadow);
    window.draw(menuPanel);
    window.draw(titleText);
    if (!selectingLevel && !settingsClicked) {
        window.draw(newGameButton);
        window.draw(newGameText);
        window.draw(resumeGameButton);
        window.draw(resumeGameText);
        window.draw(highScoreText); // High score only in main menu
        window.draw(settingsIconOuter); // Settings icon only in main menu
        for (int i = 0; i < 8; ++i) {
            window.draw(settingsIconTeeth[i]);
        }
        window.draw(settingsIconInner); // Draw inner circle last
    } else if (selectingLevel) {
        window.draw(level1Button);
        window.draw(level1Text);
        window.draw(level2Button);
        window.draw(level2Text);
        window.draw(level3Button);
        window.draw(level3Text);
    } else if (settingsClicked) {
        window.draw(soundButton);
        window.draw(soundButtonText);
        window.draw(speedButton);
        window.draw(speedButtonText);
        window.draw(resetHighScoreButton);
        window.draw(resetHighScoreButtonText);
        window.draw(settingText);
        window.draw(highScoreText); // High score only in main menu
        window.draw(settingsIconOuter); // Settings icon only in main menu
        for (int i = 0; i < 8; ++i) {
            window.draw(settingsIconTeeth[i]);
        }
        window.draw(settingsIconInner); // Draw inner circle last
    }
}

/**
 * Returns the current game speed multiplier setting.
 * @return Float value representing the game speed multiplier
 *
 * Provides access to the user-selected game speed setting.
 * Used to adjust gameplay speed in game logic.
 * Allows other components to respect the player's speed preference.
 */
float Interface::getSpeedMultiplier() const {
    switch (speedState) {
        case 0: return 0.5f;
        case 1: return 1.0f;
        case 2: return 1.5f;
        case 3: return 2.0f;
        default: return 1.0f; // Fallback, should never happen
    }
}
