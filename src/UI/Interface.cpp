#include "Interface.h"
#include "GameScreen.h"
#include <cmath>
#include <iostream>

Interface::Interface() : animationTime(0.0f) {}

void Interface::setup(sf::RenderWindow& window) {
    if (!font.loadFromFile("Resources/font.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
    }

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
}

void Interface::handleMouseEvents(sf::Event& event, bool& selectingLevel, bool resumeAvailable, sf::Sound& menuClickSound, ScreenManager& screenManager) {
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
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(screenManager.getWindow());
        if (!selectingLevel) {
            if (newGameButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                selectingLevel = true;
            }
            else if (resumeGameButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                screenManager.setScreen(std::make_unique<GameScreen>(screenManager));
            }
        } else {
            if (level1Button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                auto gameScreen = std::make_unique<GameScreen>(screenManager);
                gameScreen->resetGame(true, 1);
                screenManager.setScreen(std::move(gameScreen));
            }
            else if (level2Button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                auto gameScreen = std::make_unique<GameScreen>(screenManager);
                gameScreen->resetGame(true, 2);
                screenManager.setScreen(std::move(gameScreen));
            }
            else if (level3Button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                menuClickSound.play();
                auto gameScreen = std::make_unique<GameScreen>(screenManager);
                gameScreen->resetGame(true, 3);
                screenManager.setScreen(std::move(gameScreen));
            }
        }
    }
}

void Interface::animate(sf::Time deltaTime, bool selectingLevel, bool resumeAvailable, int score, int lives, int highScore, int level) {
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

    highScoreText.setString("High Score: " + std::to_string(highScore));
}

void Interface::renderMenu(sf::RenderWindow& window, bool selectingLevel, bool resumeAvailable, int highScore) {
    window.draw(shadow);
    window.draw(menuPanel);
    window.draw(titleText);
    if (!selectingLevel) {
        window.draw(newGameButton);
        window.draw(newGameText);
        window.draw(resumeGameButton);
        window.draw(resumeGameText);
        window.draw(highScoreText);
    } else {
        window.draw(level1Button);
        window.draw(level1Text);
        window.draw(level2Button);
        window.draw(level2Text);
        window.draw(level3Button);
        window.draw(level3Text);
    }
}