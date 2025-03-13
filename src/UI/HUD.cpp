#include "HUD.h"
#include "MenuScreen.h"
#include <iostream>

HUD::HUD() : isPopupActive(false) {
    if (!font.loadFromFile("Resources/font.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
    }
    if (!heartTexture.loadFromFile("Resources/heart.png")) {
        std::cout << "Failed to load heart.png! Using fallback texture." << std::endl;
        sf::Image fallbackImage;
        fallbackImage.create(24, 24, sf::Color::Red);
        heartTexture.loadFromImage(fallbackImage);
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

    levelText.setFont(font);
    levelText.setCharacterSize(24);
    levelText.setFillColor(sf::Color::White);
    levelText.setOutlineColor(sf::Color(0, 0, 0, 150));
    levelText.setOutlineThickness(1);
    levelText.setPosition(350, 10);

    gameOverText.setFont(font);
    gameOverText.setString("Game Over\nPress R to Restart");
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color(200, 50, 50));
    gameOverText.setOutlineColor(sf::Color(0, 0, 0, 150));
    gameOverText.setOutlineThickness(2);
    gameOverText.setPosition(250, 250);

    pauseResumeButton.setSize(sf::Vector2f(40, 40));
    pauseResumeButton.setPosition(380, 60);
    pauseResumeButton.setFillColor(sf::Color(60, 120, 180));
    pauseResumeButton.setOutlineColor(sf::Color::White);
    pauseResumeButton.setOutlineThickness(2);

    pauseResumeText.setFont(font);
    pauseResumeText.setCharacterSize(24);
    pauseResumeText.setFillColor(sf::Color::White);
    pauseResumeText.setPosition(385, 65);

    heartSprites.clear();
    for (int i = 0; i < 3; i++) {
        sf::Sprite heart;
        heart.setTexture(heartTexture);
        heart.setPosition(600 + i * 30, 10);
        heart.setScale(1.0f, 1.0f);
        heartSprites.push_back(heart);
    }

    // Initialize popup window
    popupWindow.setSize(sf::Vector2f(300, 200));
    popupWindow.setPosition(250, 200);
    popupWindow.setFillColor(sf::Color(40, 40, 60, 220));
    popupWindow.setOutlineColor(sf::Color(150, 150, 150));
    popupWindow.setOutlineThickness(2);

    popupTitle.setFont(font);
    popupTitle.setString("Game Over");
    popupTitle.setCharacterSize(30);
    popupTitle.setFillColor(sf::Color::White);
    popupTitle.setPosition(350, 220);

    exitButton.setSize(sf::Vector2f(80, 40));
    exitButton.setPosition(260, 300);
    exitButton.setFillColor(sf::Color(200, 50, 50));
    exitButton.setOutlineColor(sf::Color::White);
    exitButton.setOutlineThickness(2);

    exitButtonText.setFont(font);
    exitButtonText.setString("Exit");
    exitButtonText.setCharacterSize(20);
    exitButtonText.setFillColor(sf::Color::White);
    exitButtonText.setPosition(280, 308);

    resetButton.setSize(sf::Vector2f(80, 40));
    resetButton.setPosition(350, 300);
    resetButton.setFillColor(sf::Color(50, 200, 50));
    resetButton.setOutlineColor(sf::Color::White);
    resetButton.setOutlineThickness(2);

    resetButtonText.setFont(font);
    resetButtonText.setString("Reset");
    resetButtonText.setCharacterSize(20);
    resetButtonText.setFillColor(sf::Color::White);
    resetButtonText.setPosition(365, 308);

    mainMenuButton.setSize(sf::Vector2f(80, 40));
    mainMenuButton.setPosition(440, 300);
    mainMenuButton.setFillColor(sf::Color(50, 50, 200));
    mainMenuButton.setOutlineColor(sf::Color::White);
    mainMenuButton.setOutlineThickness(2);

    mainMenuButtonText.setFont(font);
    mainMenuButtonText.setString("Menu");
    mainMenuButtonText.setCharacterSize(20);
    mainMenuButtonText.setFillColor(sf::Color::White);
    mainMenuButtonText.setPosition(460, 308);
}

void HUD::handleEvents(sf::Event& event, GameLogic& gameLogic, ScreenManager& screenManager) {
    if (event.type == sf::Event::MouseMoved) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(screenManager.getWindow());
        if (pauseResumeButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            pauseResumeButton.setScale(1.05f, 1.05f);
        else
            pauseResumeButton.setScale(1.0f, 1.0f);

        if (isPopupActive) {
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
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(screenManager.getWindow());
        if (pauseResumeButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            screenManager.setScreen(std::make_unique<MenuScreen>(screenManager));
        }

        if (isPopupActive) {
            if (exitButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                screenManager.getWindow().close();
            }
            if (resetButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                gameLogic.resetGame(true); // Reset the game directly via GameLogic
                isPopupActive = false;
            }
            if (mainMenuButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                screenManager.setScreen(std::make_unique<MenuScreen>(screenManager));
                isPopupActive = false;
            }
        }
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && gameLogic.isGameOver()) {
        gameLogic.resetGame(true); // Reset the game directly via GameLogic
    }
}

void HUD::update(int score, int lives, int level, GameLogic& gameLogic) { // Updated with gameLogic parameter
    scoreText.setString("Score: " + std::to_string(score));
    levelText.setString("Level: " + std::to_string(level));
    for (int i = 0; i < 3; i++) {
        heartSprites[i].setColor(i < lives ? sf::Color::White : sf::Color(255, 255, 255, 50));
    }
    pauseResumeText.setString("||");

    if (gameLogic.isGameOver() && !isPopupActive) { // Now uses the passed gameLogic
        isPopupActive = true;
    }
}

void HUD::render(sf::RenderWindow& window, bool isGameOver) {
    window.draw(uiPanel);
    window.draw(scoreText);
    window.draw(levelText);
    for (const auto& heart : heartSprites) {
        window.draw(heart);
    }
    window.draw(pauseResumeButton);
    window.draw(pauseResumeText);

    if (isPopupActive) {
        window.draw(popupWindow);
        window.draw(popupTitle);
        window.draw(exitButton);
        window.draw(exitButtonText);
        window.draw(resetButton);
        window.draw(resetButtonText);
        window.draw(mainMenuButton);
        window.draw(mainMenuButtonText);
    }
}