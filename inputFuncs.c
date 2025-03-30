#include <stdio.h>
#include <stdlib.h>
#include "./headers./inputFuncs.h"

int positiveIntInput(){
    int res = 0, wrong = 0, isInputed = 0, noInput = 0;
    char inp;
    while(1){
        printf("\n\n>>");
        while(1){
            inp=getchar();
            if (inp=='\n'&&isInputed==0){
                noInput = 1;
                break;
            }
            else if (inp=='\n') break;
            else if (inp<48||inp>57){
                wrong = 1;
                break;
            }
            else{
                res = res*10+(inp-'0');
                isInputed = 1;
            }
        }
        if (wrong==0&&noInput==0){
            break;
        }
        else if (noInput==1){
            printf("\n\nInput error. Please try again\n\n");
            noInput = 0;
        }
        else{
            printf("\n\nInput error. Please try again\n\n");
            res = wrong = isInputed = 0;
            while(getchar()!='\n');
        }
    }
    return res;
}

void nameInput(char* name){
    int i = 0;
    char inp;
    while(1){
        if (i==0){
            printf("\n\n>>");
        }
        inp=getchar();
        if (inp=='\n'&&i!=0){
            name[i]='\0';
            break;
        }
        else if (inp=='\n'){
            printf("\nInput error. Please try again");
        }
        else{
            name[i]=inp;
            i++;
            name=(char*)realloc(name, (i+1)*sizeof(char));
            if (!name) {
                printf("Memory allocation error\n");
                return;
            }
        }
    }
}

void staticNameInput(char* name){
    int i = 0;
    char inp;
    while(1){
        if (i==0){
            printf("\n\n>>");
        }
        inp=getchar();
        if (inp=='\n'&&i!=0){
            name[i]='\0';
            break;
        }
        else if (inp=='\n'){
            printf("\nInput error. Please try again");
        }
        else if (i>9){
            printf("\nInput error. Max length of name: 10 characters. Please try again");
            i=0;
        }
        else{
            name[i]=inp;
            i++;
        }
    }
}
