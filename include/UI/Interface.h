#ifndef INTERFACE_H
#define INTERFACE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ScreenManager.h"

class Interface {
public:
    Interface();
    void setup(sf::RenderWindow& window);
    void handleMouseEvents(sf::Event& event, bool& selectingLevel, bool resumeAvailable, sf::Sound& menuClickSound, ScreenManager& screenManager);
    void animate(sf::Time deltaTime, bool selectingLevel, bool resumeAvailable, int score, int lives, int highScore, int level);
    void renderMenu(sf::RenderWindow& window, bool selectingLevel, bool resumeAvailable, int highScore);

private:
    sf::Font font;
    sf::Text titleText;
    sf::Text newGameText;
    sf::Text resumeGameText;
    sf::Text highScoreText;
    sf::Text level1Text;
    sf::Text level2Text;
    sf::Text level3Text;
    sf::RectangleShape menuPanel;
    sf::RectangleShape shadow;
    sf::RectangleShape newGameButton;
    sf::RectangleShape resumeGameButton;
    sf::RectangleShape level1Button;
    sf::RectangleShape level2Button;
    sf::RectangleShape level3Button;
    float animationTime;

    // New members for settings icon (gear) - Static with rectangular teeth
    sf::CircleShape settingsIconOuter; // Outer gear outline
    sf::CircleShape settingsIconInner; // Inner hollow circle
    sf::RectangleShape settingsIconTeeth[8]; // 8 rectangular teeth
    bool settingsHovered; // Track hover state
    bool settingsClicked; // Track click state for feedback
};

#endif