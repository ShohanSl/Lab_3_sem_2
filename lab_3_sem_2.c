#include <stdio.h>
#include "./headers./inputFuncs.h"
#include "./headers./tasksFuncs.h"

void main(){
    int command;
    while(1){
        printf("\nMENU\n\nChoose the task:\n1 - remainder of the division by 8\n2 - a task with board games\n0 - exit");
        command = positiveIntInput();
        if (command==1) remainderTask();
        else if (command==2) boardGamesTask();
        else if (command==0) return;
        else printf("\n\nUnknown command. Please try again\n");
    }
}