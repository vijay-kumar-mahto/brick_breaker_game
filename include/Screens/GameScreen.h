//
// Created by vijay on 3/13/25.
//

#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "Screen.h"
#include "GameLogic.h"
#include "HUD.h"
#include "ScreenManager.h"

class GameScreen : public Screen {
public:
    GameScreen(ScreenManager& screenManager);
    void handleEvents(sf::RenderWindow& window) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void resetGame(bool newGame = true, int selectedLevel = 1, float speedMultiplier = 1.0f); // Added resetGame method

private:
    ScreenManager& screenManager;
    GameLogic gameLogic;
    HUD hud;
    sf::Sound& menuClickSound;
};

#endif