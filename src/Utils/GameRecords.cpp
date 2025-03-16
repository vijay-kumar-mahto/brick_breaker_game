//
// Created by vijay on 3/13/25.
//

#include "GameRecords.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include <iostream>

/**
 * Constructor for the GameRecords class.
 *
 * Initializes the high score to zero and immediately loads any existing records
 * from the saved records file. This ensures the high score is up-to-date when
 * the game starts.
 */
GameRecords::GameRecords() : highScore(0) {
    load();
}

/**
 * Saves a new game record to the records file.
 * @param score The player's score to record
 * @param lives The number of lives remaining when the game ended
 *
 * Appends a new entry to the records CSV file with:
 * - Current timestamp
 * - Player's score
 * - Number of lives remaining
 * Also updates the in-memory high score if the new score is higher.
 * Outputs an error message to the console if the file can't be opened.
 */
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

/**
 * Loads game records from the records file.
 *
 * Reads the records CSV file line by line, parsing each record to extract:
 * - Timestamp (when the game was played)
 * - Score
 * - Lives remaining
 * Updates the in-memory high score by finding the maximum score from all records.
 * Outputs an informational message if no records file exists yet.
 */
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

/**
 * Retrieves the current high score.
 * @return The highest score achieved across all saved games
 *
 * Provides read-only access to the current high score value,
 * which is updated whenever records are loaded or a new high score is saved.
 */
int GameRecords::getHighScore() const {
    return highScore;
}

/**
 * Resets the high score and clears all game records.
 *
 * Sets the in-memory high score back to zero and truncates the records file,
 * effectively deleting all historical game data. This gives the player a fresh start.
 * Outputs an error message to the console if the file can't be opened for clearing.
 */
void GameRecords::resetHighScore() {
    highScore = 0;
    std::ofstream file("Resources/records.csv", std::ios::trunc); // Open in truncate mode to clear file
    if (file.is_open()) {
        file.close(); // Empty file
    } else {
        std::cout << "Failed to reset Resources/records.csv!" << std::endl;
    }
}