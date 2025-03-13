#include "ScreenManager.h"
#include "ResourceManager.h"

int main() {
    ResourceManager::getInstance().loadResources(); // Load resources once
    ScreenManager screenManager;
    screenManager.run();
    return 0;
}