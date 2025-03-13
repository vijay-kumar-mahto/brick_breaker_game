#include "HUD.h"
#include "MenuScreen.h"
#include <iostream>

HUD::HUD() {
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
}

void HUD::handleEvents(sf::Event& event, GameLogic& gameLogic, ScreenManager& screenManager) {
    if (event.type == sf::Event::MouseMoved) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(screenManager.getWindow());
        if (pauseResumeButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            pauseResumeButton.setScale(1.05f, 1.05f);
        else
            pauseResumeButton.setScale(1.0f, 1.0f);
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(screenManager.getWindow());
        if (pauseResumeButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            screenManager.setScreen(std::make_unique<MenuScreen>(screenManager));
        }
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && gameLogic.isGameOver()) {
        gameLogic.resetGame(true); // Reset the game directly via GameLogic
    }
}

void HUD::update(int score, int lives, int level) {
    scoreText.setString("Score: " + std::to_string(score));
    levelText.setString("Level: " + std::to_string(level));
    for (int i = 0; i < 3; i++) {
        heartSprites[i].setColor(i < lives ? sf::Color::White : sf::Color(255, 255, 255, 50));
    }
    pauseResumeText.setString("||");
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
    if (isGameOver) {
        window.draw(gameOverText);
    }
}