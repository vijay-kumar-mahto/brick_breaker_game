#include "ScreenManager.h"
#include "MenuScreen.h"

ScreenManager::ScreenManager()
    : window(sf::VideoMode(800, 600), "Brick Breaker", sf::Style::Default)
    , currentScreen(std::make_unique<MenuScreen>(*this)) {
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(true);
}

void ScreenManager::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        if (currentScreen) {
            currentScreen->handleEvents(window);
            currentScreen->update(deltaTime);
            currentScreen->render(window);
        }
    }
}

void ScreenManager::setScreen(std::unique_ptr<Screen> newScreen) {
    currentScreen = std::move(newScreen);
}

sf::RenderWindow& ScreenManager::getWindow() {
    return window;
}