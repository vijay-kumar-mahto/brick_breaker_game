#include "Game.h"
#include "Interface.h"
#include <iostream>
#include <cmath>

Game::Game()
    : window(sf::VideoMode(800, 600), "Brick Breaker", sf::Style::Default)
    , gameState(State::Menu)
    , paddle(400, 550)
    , ball(400, 500, paddleHitSound)
    , ui(new Interface())
    , score(0)
    , lives(3)
    , level(1)
    , gameSpeed(1.0f)
    , resumeAvailable(false)
    , selectingLevel(false) {
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(true); // Ensure cursor is visible
    loadResources();
    ui->setup(window);
    records.load();
}

Game::~Game() {
    delete ui;
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (gameState == State::Menu && event.key.code == sf::Keyboard::N && !selectingLevel) {
                menuClickSound.play();
                setSelectingLevel(true);
            }
            else if (gameState == State::Menu && event.key.code == sf::Keyboard::R && resumeAvailable) {
                menuClickSound.play();
                gameState = State::Playing;
            }
            else if (gameState == State::Playing && event.key.code == sf::Keyboard::Escape) {
                gameState = State::Paused;
                resumeAvailable = true;
            }
            else if (gameState == State::Paused && event.key.code == sf::Keyboard::Escape) {
                gameState = State::Playing;
            }
            else if (gameState == State::GameOver && event.key.code == sf::Keyboard::R) {
                menuClickSound.play();
                resetGame(true);
                gameState = State::Playing;
            }
        }

        ui->handleMouseEvents(event, gameState, resumeAvailable, menuClickSound, *this);
    }
    // Reset cursor state to ensure responsiveness
    window.setMouseCursorVisible(true);
}

void Game::update(sf::Time deltaTime) {
    if (gameState == State::Menu || gameState == State::Paused || gameState == State::GameOver) {
        ui->animate(deltaTime, gameState, resumeAvailable, score, lives, records.getHighScore(), level);
        return;
    }

    paddle.update(deltaTime, window);
    ball.update(deltaTime, paddle, window);

    for (auto it = bricks.begin(); it != bricks.end();) {
        if (ball.getBounds().intersects(it->getBounds())) {
            ball.bounceVertical();
            score += it->hit() ? 10 : 5;
            if (it->isDestroyed()) {
                brickBreakSound.play();
                if (rand() % 100 < 20)
                    spawnPowerUp(it->getPosition());
                it = bricks.erase(it);
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }

    for (auto it = powerUps.begin(); it != powerUps.end();) {
        if (paddle.getBounds().intersects(it->getBounds())) {
            powerUpSound.play();
            it->applyEffect(paddle, ball);
            it = powerUps.erase(it);
        } else {
            it->update(deltaTime);
            if (it->isExpired()) it = powerUps.erase(it);
            else ++it;
        }
    }

    if (ball.isOutOfBounds()) {
        lifeLostSound.play();
        lives--;
        ball.reset();
        paddle.reset();
        if (lives <= 0) {
            records.save(score, lives);
            gameState = State::GameOver;
        }
    }

    if (bricks.empty() && level < 3) {
        level++;
        nextLevel();
    } else if (bricks.empty() && level == 3) {
        gameState = State::GameOver;
    }

    ui->updateGameUI(score, lives, level);
}

void Game::render() {
    window.clear(sf::Color(20, 20, 40));

    if (gameState == State::Menu || gameState == State::Paused) {
        ui->renderMenu(window, gameState, resumeAvailable, records.getHighScore(), selectingLevel);
    } else {
        ui->renderGame(window, gameState);
        paddle.draw(window);
        ball.draw(window);
        for (const auto& brick : bricks) brick.draw(window);
        for (const auto& powerUp : powerUps) powerUp.draw(window);
    }

    window.display();
}

sf::RenderWindow& Game::getWindow() {
    return window;
}

void Game::loadResources() {
    if (!paddleHitBuffer.loadFromFile("Resources/paddle_hit.wav")) std::cout << "Failed to load paddle_hit.wav!" << std::endl;
    paddleHitSound.setBuffer(paddleHitBuffer);

    if (!brickBreakBuffer.loadFromFile("Resources/brick_break.wav")) std::cout << "Failed to load brick_break.wav!" << std::endl;
    brickBreakSound.setBuffer(brickBreakBuffer);

    if (!powerUpBuffer.loadFromFile("Resources/power_up.wav")) std::cout << "Failed to load power_up.wav!" << std::endl;
    powerUpSound.setBuffer(powerUpBuffer);

    if (!lifeLostBuffer.loadFromFile("Resources/life_lost.wav")) std::cout << "Failed to load life_lost.wav!" << std::endl;
    lifeLostSound.setBuffer(lifeLostBuffer);

    if (!menuClickBuffer.loadFromFile("Resources/menu_click.wav")) std::cout << "Failed to load menu_click.wav!" << std::endl;
    menuClickSound.setBuffer(menuClickBuffer);
}

void Game::resetGame(bool newGame, int selectedLevel) {
    if (newGame) {
        bricks.clear();
        powerUps.clear();
        ball.reset();
        paddle.reset();
        score = 0;
        lives = 3;
        level = selectedLevel;
        gameSpeed = 1.0f;
        resumeAvailable = false;
        selectingLevel = false;
        nextLevel();
    } else {
        ball.reset();
        paddle.reset();
    }
}

void Game::spawnPowerUp(sf::Vector2f position) {
    powerUps.emplace_back(position, rand() % 2 == 0 ? PowerUp::Type::SpeedBoost : PowerUp::Type::PaddleSize);
}

void Game::nextLevel() {
    bricks.clear();
    ball.setSpeed(400.0f + (level - 1) * 50.0f);
    gameSpeed = 1.0f + (level - 1) * 0.2f;

    int rows = 4 + level;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < rows; j++) {
            bricks.emplace_back(100 * i + 50, 50 * j + 70, (rand() % (level + 1)) + 1);
        }
    }
}