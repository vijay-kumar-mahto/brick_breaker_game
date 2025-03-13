#ifndef INTERFACE_H
#define INTERFACE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.h"
class Game;
class Interface {
public:
    Interface();
    void setup(sf::RenderWindow& window);
    void handleMouseEvents(sf::Event& event, State& gameState, bool resumeAvailable, sf::Sound& menuClickSound, Game& game);
    void animate(sf::Time deltaTime, State gameState, bool resumeAvailable, int score, int lives, int highScore, int level);
    void updateGameUI(int score, int lives, int level);
    void renderMenu(sf::RenderWindow& window, State gameState, bool resumeAvailable, int highScore, bool selectingLevel);
    void renderGame(sf::RenderWindow& window, State gameState);
private:
    sf::Font font;
    sf::Text titleText;
    sf::Text newGameText;
    sf::Text resumeGameText;
    sf::Text scoreText;
    // sf::Text livesText; // Removed
    sf::Text highScoreText;
    sf::Text gameOverText;
    sf::Text levelText;
    sf::Text level1Text;
    sf::Text level2Text;
    sf::Text level3Text;
    sf::Text pauseResumeText;
    sf::RectangleShape uiPanel;
    sf::RectangleShape menuPanel;
    sf::RectangleShape shadow;
    sf::RectangleShape newGameButton;
    sf::RectangleShape resumeGameButton;
    sf::RectangleShape level1Button;
    sf::RectangleShape level2Button;
    sf::RectangleShape level3Button;
    sf::RectangleShape pauseResumeButton;
    sf::Texture heartTexture; // Added
    std::vector<sf::Sprite> heartSprites; // Added
    float animationTime;
};
#endif