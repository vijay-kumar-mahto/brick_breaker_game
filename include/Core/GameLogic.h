#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "PowerUp.h"
#include "GameRecords.h"
#include "ResourceManager.h"

class GameLogic {
public:
    GameLogic(sf::Sound& paddleHitSound);
    void update(sf::Time deltaTime, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void resetGame(bool newGame = true, int selectedLevel = 1);
    void nextLevel();
    int getScore() const { return score; }
    int getLives() const { return lives; }
    int getLevel() const { return level; }
    int getHighScore() const { return records.getHighScore(); }
    bool isGameOver() const { return lives <= 0 || (bricks.empty() && level == 3); }
    bool isPaused() const { return paused; } // New: Check paused state
    void setPaused(bool pause) { paused = pause; } // New: Set paused state

private:
    void spawnPowerUp(sf::Vector2f position);
    Paddle paddle;
    Ball ball;
    std::vector<Brick> bricks;
    std::vector<PowerUp> powerUps;
    GameRecords records;
    sf::Sound& paddleHitSound;
    sf::Sound brickBreakSound;
    sf::Sound powerUpSound;
    sf::Sound lifeLostSound;
    int score;
    int lives;
    int level;
    float gameSpeed;
    bool paused = false; // New: Paused state
};

#endif