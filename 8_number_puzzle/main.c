#include "puzzle.h"
#include "Hall_of_fame.h"
#include "add_to_fame.h"

#include<string.h>
#include<stdio.h>
#include<stdlib.h>


int main(){

    printf("This is 8 number puzzle game. You have to match the puzzle with target puzzle by moving the numbers.\n\n");

    printf("For New game enter 'N'\nFor Hall of Fame enter 'H'\n\nEnter your choice: ");

    char a;
    scanf("%ch", &a);

    switch(a){
        case 'N':
            system("CLS");
            puzzle();
            break;
        case 'H':
            system("CLS");
            printf("\n\t\tThis is the Hall of Fame.\n\n\n");
            fame();
            break;
        default:
            printf("\n\t\tPlease Enter a Valid keyword.\n\n");
    }

    return 0;
}
