//
// Created by vijay on 3/13/25.
//

#include "GameLogic.h"
#include <iostream>
#include <cmath>

/**
 * Constructor for GameLogic class.
 * @param paddleHitSound Reference to the sound effect played when ball hits paddle
 *
 * Initializes the game components including paddle, ball, and game state variables
 * such as score, lives, level, and game speed settings.
 */
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
    , baseBallSpeed(300.0f){
    records.load();
    nextLevel();
}

/**
 * Updates game state based on time elapsed since last frame.
 * @param deltaTime Time elapsed since the last update
 * @param window Reference to the game window for input detection and boundaries
 *
 * Handles movement, collisions, power-ups, and game state changes.
 * Only updates game elements if the game is not paused.
 */
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

/**
 * Renders all game elements to the window.
 * @param window Reference to the render window where game elements will be drawn
 *
 * Draws the paddle, ball, bricks, power-ups, and any UI elements in their current state.
 */
void GameLogic::render(sf::RenderWindow& window) {
    paddle.draw(window);
    ball.draw(window);
    for (const auto& brick : bricks) brick.draw(window);
    for (const auto& powerUp : powerUps) powerUp.draw(window);
}

/**
 * Resets the game state.
 * @param newGame If true, resets score and sets up a brand new game
 * @param selectedLevel The level to initialize (affects brick layout and difficulty)
 * @param speedMultiplier Adjusts the game's speed
 *
 * Resets the player's paddle, ball position, and sets up brick configurations
 * based on the selected level.
 */
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

/**
 * Creates a new power-up at the specified position.
 * @param position Vector containing the x,y coordinates where the power-up should appear
 *
 * Randomly determines the type of power-up to spawn and adds it to the active power-ups list.
 * Typically called when a brick is destroyed.
 */
void GameLogic::spawnPowerUp(sf::Vector2f position) {
    powerUps.emplace_back(position, rand() % 2 == 0 ? PowerUp::Type::SpeedBoost : PowerUp::Type::PaddleSize);
}

/**
 * Advances the game to the next level.
 *
 * Increases the level counter, sets up a new brick configuration,
 * potentially increases difficulty, and resets the ball and paddle positions.
 */
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

/**
 * Sets the multiplier for ball speed.
 * @param multiplier The factor by which to multiply the base ball speed
 *
 * Adjusts the ball's speed, allowing for dynamic difficulty changes
 * or implementing speed-related power-ups.
 */
void GameLogic::setBallSpeedMultiplier(float multiplier) {
    gameSpeedMultiplier = multiplier;
    ball.setSpeed(baseBallSpeed * gameSpeedMultiplier); // Apply immediately
}