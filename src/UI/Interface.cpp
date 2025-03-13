#include "Interface.h"
#include "Game.h"
#include <cmath>
#include <iostream>

Interface::Interface() : animationTime(0.0f) {}

void Interface::setup(sf::RenderWindow& window) {
    if (!font.loadFromFile("Resources/font.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
    }
    if (!heartTexture.loadFromFile("Resources/heart.png")) {
        std::cout << "Failed to load heart.png! Using fallback texture." << std::endl;
        sf::Image fallbackImage;
        fallbackImage.create(24, 24, sf::Color::Red);
        heartTexture.loadFromImage(fallbackImage);
    } else {
        std::cout << "Successfully loaded heart.png" << std::endl;
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

    newGameButton.setSize(sf::Vector2f(200, 60));
    newGameButton.setPosition(300, 250);
    newGameButton.setFillColor(sf::Color(60, 120, 180));
    newGameButton.setOutlineColor(sf::Color::White);
    newGameButton.setOutlineThickness(2);

    newGameText.setFont(font);
    newGameText.setString("New Game (N)");
    newGameText.setCharacterSize(24);
    newGameText.setFillColor(sf::Color::White);
    newGameText.setPosition(320, 260);

    resumeGameButton.setSize(sf::Vector2f(200, 60));
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
    highScoreText.setFillColor(sf::Color::Yellow);
    highScoreText.setOutlineColor(sf::Color(0, 0, 0, 150));
    highScoreText.setOutlineThickness(1);
    highScoreText.setPosition(150, 10);

    gameOverText.setFont(font);
    gameOverText.setString("Game Over\nPress R to Restart");
    gameOverText.setCharacterSize(48);
    gameOverText.setFillColor(sf::Color(200, 50, 50));
    gameOverText.setOutlineColor(sf::Color(0, 0, 0, 150));
    gameOverText.setOutlineThickness(2);
    gameOverText.setPosition(250, 250);

    levelText.setFont(font);
    levelText.setCharacterSize(24);
    levelText.setFillColor(sf::Color::White);
    levelText.setOutlineColor(sf::Color(0, 0, 0, 150));
    levelText.setOutlineThickness(1);
    levelText.setPosition(350, 10);

    level1Button.setSize(sf::Vector2f(100, 40));
    level1Button.setPosition(250, 250);
    level1Button.setFillColor(sf::Color(60, 120, 180));
    level1Button.setOutlineColor(sf::Color::White);
    level1Button.setOutlineThickness(2);

    level1Text.setFont(font);
    level1Text.setString("Level 1");
    level1Text.setCharacterSize(20);
    level1Text.setFillColor(sf::Color::White);
    level1Text.setPosition(260, 255);

    level2Button.setSize(sf::Vector2f(100, 40));
    level2Button.setPosition(350, 250);
    level2Button.setFillColor(sf::Color(60, 120, 180));
    level2Button.setOutlineColor(sf::Color::White);
    level1Button.setOutlineThickness(2);

    level2Text.setFont(font);
    level2Text.setString("Level 2");
    level2Text.setCharacterSize(20);
    level2Text.setFillColor(sf::Color::White);
    level2Text.setPosition(360, 255);

    level3Button.setSize(sf::Vector2f(100, 40));
    level3Button.setPosition(450, 250);
    level3Button.setFillColor(sf::Color(60, 120, 180));
    level3Button.setOutlineColor(sf::Color::White);
    level3Button.setOutlineThickness(2);

    level3Text.setFont(font);
    level3Text.setString("Level 3");
    level3Text.setCharacterSize(20);
    level3Text.setFillColor(sf::Color::White);
    level3Text.setPosition(460, 255);

    pauseResumeButton.setSize(sf::Vector2f(40, 40));
    pauseResumeButton.setPosition(380, 60);
    pauseResumeButton.setFillColor(sf::Color(60, 120, 180));
    pauseResumeButton.setOutlineColor(sf::Color::White);
    pauseResumeButton.setOutlineThickness(2);

    pauseResumeText.setFont(font);
    pauseResumeText.setCharacterSize(24);
    pauseResumeText.setFillColor(sf::Color::White);
    pauseResumeText.setPosition(385, 65);

    // Initialize heart sprites (max 3 lives)
    heartSprites.clear();
    for (int i = 0; i < 3; i++) {
        sf::Sprite heart;
        heart.setTexture(heartTexture);
        heart.setPosition(600 + i * 30, 10); // Adjusted left to (600, 10), (630, 10), (660, 10)
        heart.setScale(1.0f, 1.0f);
        heartSprites.push_back(heart);
        std::cout << "Heart " << i << " initialized at (" << 600 + i * 30 << ", 10)" << std::endl;
    }
}

void Interface::handleMouseEvents(sf::Event& event, State& gameState, bool resumeAvailable, sf::Sound& menuClickSound, Game& game) {
    if (event.type == sf::Event::MouseMoved) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(game.getWindow());
        if (newGameButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            newGameButton.setScale(1.05f, 1.05f);
        else
            newGameButton.setScale(1.0f, 1.0f);
        if (resumeGameButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && resumeAvailable)
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
        if (pauseResumeButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
            pauseResumeButton.setScale(1.05f, 1.05f);
        else
            pauseResumeButton.setScale(1.0f, 1.0f); // Fixed: Completed the setScale call
    }

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(game.getWindow());
        if (gameState == State::Menu) {
            if (newGameButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && !game.isSelectingLevel()) {
                menuClickSound.play();
                game.setSelectingLevel(true);
            }
            else if (resumeGameButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)) && resumeAvailable) {
                menuClickSound.play();
                gameState = State::Playing;
            }
            else if (game.isSelectingLevel()) {
                if (level1Button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    menuClickSound.play();
                    game.resetGame(true, 1);
                    gameState = State::Playing;
                }
                else if (level2Button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    menuClickSound.play();
                    game.resetGame(true, 2);
                    gameState = State::Playing;
                }
                else if (level3Button.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                    menuClickSound.play();
                    game.resetGame(true, 3);
                    gameState = State::Playing;
                }
            }
        }
        else if (gameState == State::Playing && pauseResumeButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            menuClickSound.play();
            gameState = State::Paused;
        }
        else if (gameState == State::Paused && pauseResumeButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            menuClickSound.play();
            gameState = State::Playing;
        }
    }
}

void Interface::animate(sf::Time deltaTime, State gameState, bool resumeAvailable, int score, int lives, int highScore, int level) {
    animationTime += deltaTime.asSeconds();
    float pulse = 0.5f + 0.5f * std::sin(animationTime * 2.0f);

    if (gameState == State::Menu) {
        titleText.setScale(1.0f + 0.03f * pulse, 1.0f + 0.03f * pulse);
        sf::Color buttonColor = newGameButton.getFillColor();
        buttonColor.a = static_cast<sf::Uint8>(200 + 55 * pulse);
        newGameButton.setFillColor(buttonColor);
        resumeGameButton.setFillColor(resumeAvailable ? buttonColor : sf::Color(60, 120, 180, 100));
        level1Button.setFillColor(buttonColor);
        level2Button.setFillColor(buttonColor);
        level3Button.setFillColor(buttonColor);
    } else if (gameState == State::GameOver) {
        sf::Color color = gameOverText.getFillColor();
        color.a = static_cast<sf::Uint8>(150 + 105 * pulse);
        gameOverText.setFillColor(color);
    }

    highScoreText.setString("High Score: " + std::to_string(highScore));
    scoreText.setString("Score: " + std::to_string(score));
    levelText.setString("Level: " + std::to_string(level));
    pauseResumeText.setString(gameState == State::Playing ? "||" : "\u25B6");
}

void Interface::updateGameUI(int score, int lives, int level) {
    scoreText.setString("Score: " + std::to_string(score));
    levelText.setString("Level: " + std::to_string(level));
    for (int i = 0; i < 3; i++) {
        heartSprites[i].setColor(i < lives ? sf::Color::White : sf::Color(255, 255, 255, 50));
        std::cout << "Heart " << i << " visibility: " << (i < lives ? "Visible" : "Faded") << std::endl;
    }
}

void Interface::renderGame(sf::RenderWindow& window, State gameState) {
    window.draw(uiPanel);
    window.draw(scoreText);
    window.draw(highScoreText);
    window.draw(levelText);
    for (size_t i = 0; i < heartSprites.size(); i++) {
        window.draw(heartSprites[i]);
        std::cout << "Drawing heart " << i << " at (" << heartSprites[i].getPosition().x << ", " << heartSprites[i].getPosition().y << ")" << std::endl;
    }
    window.draw(pauseResumeButton);
    window.draw(pauseResumeText);
    if (gameState == State::GameOver) {
        window.draw(shadow);
        window.draw(gameOverText);
    }
}

void Interface::renderMenu(sf::RenderWindow& window, State gameState, bool resumeAvailable, int highScore, bool selectingLevel) {
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