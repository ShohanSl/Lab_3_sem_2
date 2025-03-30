#include <stdio.h>
#include <stdlib.h>
#include "./headers./boardGameTaskFuctions.h"
#include "./headers./inputFuncs.h"

void nameReading(char* name){  //Выводит содержимое поля 'name'
    printf("%s\n", name);
}

void addNewGame(struct BoardGame **list, int gamesCount) {  //Добавление нового экземпляра структуры в массив
    int i=0;
    char out;
    gamesCount++;
    *list = (struct BoardGame*)realloc(*list, gamesCount*sizeof(struct BoardGame));
    if (!(*list)) {
        printf("Memory allocation error\n");
        return;
    }
    (*list)[gamesCount-1].name = (char*)malloc(sizeof(char));
    if (!((*list)[gamesCount-1].name)) {
        printf("Memory allocation error\n");
        return;
    }
    printf("\nEnter a name of game:");
    nameInput((*list)[gamesCount-1].name);
    printf("\nEnter a cost of game:");
    (*list)[gamesCount-1].cost = positiveIntInput();
    printf("\nEnter a genre of game:");
    staticNameInput((*list)[gamesCount-1].Parameters.genre);
    printf("\nEnter a maximum number of players:");
    (*list)[gamesCount-1].Parameters.maxPlayers = positiveIntInput();
    printf("\nGame added\n\nName: ");
    nameReading((*list)[gamesCount-1].name);
    printf("\nCost: %d\n\nGame genre: ", (*list)[gamesCount-1].cost);
    nameReading((*list)[gamesCount-1].Parameters.genre);
    printf("\nA maximum number of players: %d\n", (*list)[gamesCount-1].Parameters.maxPlayers);
}

void findGame(struct BoardGame *list, int gamesCount){  //Ищет в массиве структуру с подходящим полем 'cost'
    int reqCost, isFound=0;
    printf("\nEnter the required cost");
    reqCost = positiveIntInput();
    printf("\nGames with this cost:\n");
    for (int i=0; i<gamesCount; i++){
        if (list[i].cost==reqCost){
            nameReading(list[i].name);
            putchar('\n');
            isFound = 1;
        }
    }
    if (isFound==0) printf("\nThere are no games with this cost\n");
}

void deleteGame(struct BoardGame **list, int *gamesCount){  //Удаляет из массива структуру с подходящим полем 'name'
    if (*gamesCount == 0) {
        printf("The list is empty\n");
        return;
    }
    int i, j=1, success;
    char* reqName;
    reqName=(char*)malloc(sizeof(char));
    if (!reqName) {
        printf("Memory allocation error\n");
        return;
    }
    printf("\nEnter a name of game you mant to delete:");
    nameInput(reqName);
    for (i=0; i<(*gamesCount); i++){
        success=0;
        if (reqName[0]==(*list)[i].name[0]){
            while(1){
                if (reqName[j]=='\0'&&(*list)[i].name[j]=='\0'){
                    success = 1;
                    break;
                }
                else if (reqName[j]=='\0'||(*list)[i].name[j]=='\0') break;
                else if (reqName[j]==(*list)[i].name[j]) j++;
                else break;
            }
            j=1;
            if (success==1){
                free((*list)[i].name);
                int k;
                struct BoardGame *newList;
                int newCount = *gamesCount - 1;
                newList=(struct BoardGame*)malloc(((*gamesCount)-1)*sizeof(struct BoardGame));
                if (!newList) {
                    printf("Memory allocation error\n");
                    return;
                }
                for (int k = 0; k < i; k++) newList[k] = (*list)[k];
                for (int k = i; k < newCount; k++) newList[k] = (*list)[k+1];
                free(*list);
                *list = newList;
                *gamesCount = newCount;
            }
        }
    }
    if (!success) {
        printf("Game '%s' not found\n", reqName);
    }
    else{
        printf("\nThe list of games after deleting:\n");
        for (i=0; i<*gamesCount; i++){
            nameReading((*list)[i].name);
        }
    }
    free(reqName);
}

void cleanupBoardGames(struct BoardGame *list, int gamesCount) {  //Очищает память от массива структур
    if (!list) return;
    
    for (int i = 0; i < gamesCount; i++) {
        free(list[i].name);
    }
    free(list);
}
