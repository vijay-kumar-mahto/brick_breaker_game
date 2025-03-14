#include "GameLogic.h"
#include <iostream>
#include <cmath>

GameLogic::GameLogic(sf::Sound& paddleHitSound)
    : paddle(400, 550)
    , ball(400, 500, paddleHitSound)
    , paddleHitSound(paddleHitSound)
    , score(0)
    , lives(3)
    , level(1)
    , paused(false)
    , gameSpeed(1.0f)
    , gameSpeedMultiplier(1.0f)
    , baseBallSpeed(100.0f){
    //brickBreakSound.setBuffer(ResourceManager::getInstance().getSoundBuffer("brick_break"));
    //powerUpSound.setBuffer(ResourceManager::getInstance().getSoundBuffer("power_up"));
    //lifeLostSound.setBuffer(ResourceManager::getInstance().getSoundBuffer("life_lost"));
    records.load();
    nextLevel();
}

void GameLogic::update(sf::Time deltaTime, sf::RenderWindow& window) {
    if (!paused) { // Only update if not paused
        paddle.update(deltaTime, window);
        ball.update(deltaTime, paddle, window);

        for (auto it = bricks.begin(); it != bricks.end();) {
            if (ball.getBounds().intersects(it->getBounds())) {
                ball.bounceVertical();
                score += it->hit() ? 10 : 5;
                if (it->isDestroyed()) {
                    ResourceManager::getInstance().getSound("brick_break").play();
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
                ResourceManager::getInstance().getSound("power_up").play();
                it->applyEffect(paddle, ball);
                it = powerUps.erase(it);
            } else {
                it->update(deltaTime);
                if (it->isExpired()) it = powerUps.erase(it);
                else ++it;
            }
        }

        if (ball.isOutOfBounds()) {
            ResourceManager::getInstance().getSound("life_lost").play();
            lives--;
            ball.reset();
            paddle.reset();
            if (lives <= 0) {
                records.save(score, lives);
            }
        }

        if (bricks.empty() && level < 3) {
            level++;
            nextLevel();
        }
    }
}

void GameLogic::render(sf::RenderWindow& window) {
    paddle.draw(window);
    ball.draw(window);
    for (const auto& brick : bricks) brick.draw(window);
    for (const auto& powerUp : powerUps) powerUp.draw(window);
}

void GameLogic::resetGame(bool newGame, int selectedLevel, float speedMultiplier) {
    if (newGame) {
        bricks.clear();
        powerUps.clear();
        ball.reset();
        paddle.reset();
        score = 0;
        lives = 3;
        level = selectedLevel;
        //gameSpeed = 1.0f;
        gameSpeedMultiplier = speedMultiplier; // Set user-selected speed
        nextLevel();
        std::cout << "Game reset to Level " << selectedLevel << " with speed multiplier: " << gameSpeedMultiplier
                  << ", Ball speed set to: " << (baseBallSpeed * gameSpeedMultiplier) << std::endl;
    } else {
        ball.reset();
        paddle.reset();
    }
    paused = false; // Ensure paused is reset to false on new game
}

void GameLogic::spawnPowerUp(sf::Vector2f position) {
    powerUps.emplace_back(position, rand() % 2 == 0 ? PowerUp::Type::SpeedBoost : PowerUp::Type::PaddleSize);
}

void GameLogic::nextLevel() {
    bricks.clear();
    //ball.setSpeed(150.0f + (level - 1) * 50.0f);
    ball.setSpeed(baseBallSpeed * gameSpeedMultiplier);
    //gameSpeed = 1.0f + (level - 1) * 0.2f;

    int rows = 4 + level;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < rows; j++) {
            bricks.emplace_back(100 * i + 50, 50 * j + 120, (rand() % (level + 1)) + 1);
        }
    }
}

void GameLogic::setBallSpeedMultiplier(float multiplier) {
    gameSpeedMultiplier = multiplier;
    ball.setSpeed(baseBallSpeed * gameSpeedMultiplier); // Apply immediately
}