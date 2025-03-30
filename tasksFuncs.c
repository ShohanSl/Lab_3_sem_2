#include <stdio.h>
#include <stdlib.h>
#include "./headers./inputFuncs.h"
#include "./headers./tasksFuncs.h"
#include "./headers./boardGameTaskFuctions.h"

struct BitField{
    unsigned int remainder : 3;
    unsigned int other_bits : 29;
};

void remainderTask(){  //Задача с поиском остатка от деления
    int num;
    printf("\nEnter a positive integer:");
    num = positiveIntInput();
    struct BitField* bits = (struct BitField*)&num;
    printf("\nThe remainder of the division by 8: %d\n", bits->remainder);
}

void boardGamesTask(){  //Задача со структурой
    int command, gamesCount = 0;
    struct BoardGame *list;
    list = (struct BoardGame*)malloc(sizeof(struct BoardGame));
    if (!list) {
        printf("Memory allocation error\n");
        return;
    }
    addNewGame(&list, gamesCount);
    gamesCount++;
    while(1){
        printf("\nChoose operation:\n\n1 - add new game\n2 - find a game by cost\n3 - delete a game\n0 - exit");
        command = positiveIntInput();
        if (command==1){
            addNewGame(&list, gamesCount);
            gamesCount++;
        }
        else if (command==2) findGame(list, gamesCount);
        else if (command==3) deleteGame(&list, &gamesCount);
        else if (command==0) break;
        else printf("\n\nUnknown command. Please try again\n");
    }
    cleanupBoardGames(list, gamesCount);
}