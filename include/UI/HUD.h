#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "GameLogic.h"
#include "ScreenManager.h"

class HUD {
public:
    HUD();
    void handleEvents(sf::Event& event, GameLogic& gameLogic, ScreenManager& screenManager);
    void update(int score, int lives, int level, GameLogic& gameLogic);
    void render(sf::RenderWindow& window, bool isGameOver);

private:
    sf::Font font;
    sf::Text scoreText;
    sf::Text highScoreText;
    sf::Text levelText;
    sf::Text livesText;
    sf::RectangleShape uiPanel;

    sf::RectangleShape buttonPanel;
    sf::RectangleShape pauseResumeButton;
    sf::Text pauseResumeText;
    sf::RectangleShape exitButton;
    sf::Text exitButtonText;
    sf::RectangleShape resetButton;
    sf::Text resetButtonText;
    sf::RectangleShape mainMenuButton;
    sf::Text mainMenuButtonText;

    sf::RectangleShape popupWindow;
    sf::Text popupTitle;
    sf::RectangleShape popupExitButton;
    sf::Text popupExitButtonText;
    sf::RectangleShape popupResetButton;
    sf::Text popupResetButtonText;
    sf::RectangleShape popupMainMenuButton;
    sf::Text popupMainMenuButtonText;
    bool isPopupActive;
};

#endif