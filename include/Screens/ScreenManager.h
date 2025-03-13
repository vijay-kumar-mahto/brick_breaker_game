#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Screen.h"

class ScreenManager {
public:
    ScreenManager();
    void run();
    void setScreen(std::unique_ptr<Screen> newScreen);
    sf::RenderWindow& getWindow();

private:
    sf::RenderWindow window;
    std::unique_ptr<Screen> currentScreen;
};

#endif