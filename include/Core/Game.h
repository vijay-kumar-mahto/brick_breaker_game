#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "PowerUp.h"
#include "State.h"
#include "GameRecords.h"
class Interface;
class Game {
public:
    Game();
    ~Game();
    void run();
    sf::RenderWindow& getWindow();
    void resetGame(bool newGame = true, int selectedLevel = 1);
    bool isSelectingLevel() const { return selectingLevel; } // Added accessor
    void setSelectingLevel(bool value) { selectingLevel = value; } // Added setter
private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void loadResources();
    void spawnPowerUp(sf::Vector2f position);
    void nextLevel();
    sf::RenderWindow window;
    State gameState;
    Paddle paddle;
    Ball ball;
    std::vector<Brick> bricks;
    std::vector<PowerUp> powerUps;
    Interface* ui;
    GameRecords records;
    sf::SoundBuffer paddleHitBuffer;
    sf::SoundBuffer brickBreakBuffer;
    sf::SoundBuffer powerUpBuffer;
    sf::SoundBuffer lifeLostBuffer;
    sf::SoundBuffer menuClickBuffer;
    sf::Sound paddleHitSound;
    sf::Sound brickBreakSound;
    sf::Sound powerUpSound;
    sf::Sound lifeLostSound;
    sf::Sound menuClickSound;
    int score;
    int lives;
    int level;
    float gameSpeed;
    bool resumeAvailable;
    bool selectingLevel;
};
#endif