//Шохан В.К.
//1. Найти и вывести остаток от деления целого числа на 8, не выполняя деления
// и не используя операцию взятия остатка от деления.
// 2. Структура содержит информацию о настольных играх: стоимость (число),
// название (указатель), вложенную структуру – жанр игры (строка
// фиксированной длины) и максимальное количество игроков. Найти игры с
// заданной стоимостью. Удалить игру с заданным названием.
//30.03.25

#include <stdio.h>
#include "./headers./inputFuncs.h"
#include "./headers./tasksFuncs.h"

void main(){ //Главное меню
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