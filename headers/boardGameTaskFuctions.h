#ifndef BOARDGAMETASKFUNCTIONS_H
#define BOARDGAMETASKFUNCTIONS_H

struct BoardGame{
    int cost;
    char* name;
    struct{
        char genre[10];
        int maxPlayers;
    }Parameters;
};

void nameReading();

void addNewGame();

void findGame();

void deleteGame();

void cleanupBoardGames();

#endif