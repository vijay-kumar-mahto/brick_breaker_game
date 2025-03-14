#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "Screen.h"
#include "Interface.h"
#include "ScreenManager.h"
#include "GameRecords.h" // Added include for GameRecords

class MenuScreen : public Screen {
public:
    MenuScreen(ScreenManager& screenManager);
    void handleEvents(sf::RenderWindow& window) override;
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    ScreenManager& screenManager;
    Interface interface;
    GameRecords records;
    bool selectingLevel;
    bool resumeAvailable;
    sf::Sound& menuClickSound;
    int highScore; // Added to store high score locally
};

#endif