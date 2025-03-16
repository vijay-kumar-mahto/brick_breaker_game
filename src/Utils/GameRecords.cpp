#include "GameRecords.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include <iostream>

GameRecords::GameRecords() : highScore(0) {
    load();
}

void GameRecords::save(int score, int lives) {
    std::ofstream file("Resources/records.csv", std::ios::app);
    if (file.is_open()) {
        std::time_t now = std::time(nullptr);
        std::string timestamp = std::ctime(&now);
        timestamp.pop_back();
        file << timestamp << "," << score << "," << lives << "\n";
        file.close();
        if (score > highScore) highScore = score;
    } else {
        std::cout << "Failed to open Resources/records.csv for writing!" << std::endl;
    }
}

void GameRecords::load() {
    std::ifstream file("Resources/records.csv");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string timestamp, scoreStr, livesStr;
            std::getline(ss, timestamp, ',');
            std::getline(ss, scoreStr, ',');
            std::getline(ss, livesStr, ',');
            int score = std::stoi(scoreStr);
            if (score > highScore) highScore = score;
        }
        file.close();
    } else {
        std::cout << "No Resources/records.csv found, starting fresh." << std::endl;
    }
}

int GameRecords::getHighScore() const {
    return highScore;
}

void GameRecords::resetHighScore() {
    highScore = 0;
    std::ofstream file("Resources/records.csv", std::ios::trunc); // Open in truncate mode to clear file
    if (file.is_open()) {
        file.close(); // Empty file
    } else {
        std::cout << "Failed to reset Resources/records.csv!" << std::endl;
    }
}