#ifndef GAME_RECORDS_H
#define GAME_RECORDS_H

#include <string>

class GameRecords {
public:
    GameRecords();
    void save(int score, int lives);
    void load();
    int getHighScore() const;
    void resetHighScore(); // Added for reset feature

private:
    int highScore;
};

#endif