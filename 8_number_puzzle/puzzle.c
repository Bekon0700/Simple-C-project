#include "puzzle.h"
#include "add_to_fame.h"

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void puzzle(){
    int arr[3][3];
    int a = 1;
    for(int i = 0;i < 3; i++){
        for(int j = 0; j<3; j++){
            if(i == 2 && j == 2){
                a = 0;
            }
            arr[i][j] = a;
            a++;
        }
    }

    printf("Enter 8 Number randomly from 1 to 8(Without repetition): \n");
    int n[8];
    for(int i=0;i<8; i++){
        printf("Enter %dth number: ",i+1);
        scanf("%d", &n[i]);
    }

    int c,r;
    printf("Where do u want to add the free space(Enter row, col): ");
    scanf("%d %d", &r, &c);

    int t_arr[3][3];
    int p = 0;
    for(int i = 0;i < 3; i++){
        for(int j = 0; j<3; j++){
            if(i == (r-1) && j == (c-1)){
                t_arr[i][j] = 0;
            }
            else{
                t_arr[i][j] = n[p];
                p++;
            }
        }
    }

    system("CLS");
    printf("\n\t\t\tThis is the target puzzle. please, Remember it.\n\n\n");
    printf("-------------\n");
    for(int i = 0;i < 3; i++){
        printf("|");
        for(int j = 0; j<3; j++){
            printf("% d |", arr[i][j]);
            }
            printf("\n");
            printf("-------------");
            printf("\n");
    }
    printf("\n\n");
    system("PAUSE");

    int z = 0;

    c = c-1;
    r = r-1;
    int flag = 0;
    while(flag == 0){
        system("CLS");

        printf("-------------\n");
        for(int i = 0;i < 3; i++){
                printf("|");
            for(int j = 0; j<3; j++){
                printf("% d |", t_arr[i][j]);
            }
            printf("\n");
            printf("-------------");
            printf("\n");
        }


        int k = 0;
        for(int i = 0;i < 3; i++){
            for(int j = 0; j<3; j++){
                if(arr[i][j] == t_arr[i][j]){
                    k++;
                }
            }
        }

        if(k == 9){
            printf("\n\n\t\tCongratulation, You successfully solve the puzzle.\n");
            add_to_fame();
            break;
        }

        //printf("\n\n%d\n\n", z);
        if(z % 3 == 0 && z != 0){
            printf("Do you want to surrender?\nIf so, please enter 'S' for surrender: ");
            char surr[1];
            scanf("%s", surr);
            if(surr[0] == 'S'){
                system("CLS");
                printf("\n\n\t\t\t   You surrender.\n\t\t\tBetter luck next time.\n\n\n");
                break;
            }
        }


        printf("\n\nUp = 8,\tRight = 6,\tDown = 2,\tLeft = 4\n\n");
        int l;
        if(r == 0 && c == 0){
            printf("Move Right or Down.\nEnter your choice(6 or 2): ");
            scanf("%d", &l);
            if(l == 6 || l == 2){
                l = l;
            }else{
                l = 1;
            }
        }else if(r == 0 && c == 1){
            printf("Move Right, Down, Left\nEnter your choice(6 or 2 or 4): ");
            scanf("%d", &l);
            if(l == 4 || l == 6 || l == 2){
                l = l;
            }else{
                l = 1;
            }
        }else if(r == 0 && c == 2){
            printf("Move Left, Down\nEnter your choice(4 or 2): ");
            scanf("%d", &l);
            if(l == 4 || l == 2){
                l = l;
            }else{
                l = 1;
            }
        }else if(r == 1 && c == 0){
            printf("Move Up, Right, Down\nEnter your choice(8 or 6 or 2): ");
            scanf("%d", &l);
            if(l == 8 || l == 6 || l == 2){
                l = l;
            }else{
                l = 1;
            }
        }else if(r == 1 && c == 1){
            printf("Move Up, Right, Down, Left\nEnter your choice(8 or 6 or 2 or 4): ");
            scanf("%d", &l);
            if(l == 8 || l == 6 || l == 2 || l == 4){
                l = l;
            }else{
                l = 1;
            }
        }else if(r == 1 && c == 2){
            printf("Move Left, Up, Down\nEnter your choice(4 or 8 or 2): ");
            scanf("%d", &l);
            if(l == 4 || l == 8 || l == 2){
                l = l;
            }else{
                l = 1;
            }
        }else if(r == 2 && c == 0){
            printf("Move Up, Right\nEnter your choice(8 or 6): ");
            scanf("%d", &l);
            if(l == 8 || l == 6){
                l = l;
            }else{
                l = 1;
            }
        }else if(r == 2 && c == 1){
            printf("Move Up, Right, Left\nEnter your choice(8 or 6 or 4): ");
            scanf("%d", &l);
            if((l == 4) || (l == 6) || (l == 8)){
                l = l;
            }else{
                l = 1;
            }
        }else if(r == 2 && c == 2){
            printf("Move Up, Left\nEnter your choice(8 or 4): ");
            scanf("%d", &l);
            if(l == 4 || l == 8){
                l = l;
            }else{
                l = 1;
            }
        }

        //printf("\n\n%d\n\n", l);
        if(l == 8 || l == 6 || l == 2 || l == 4){
            int new_col, new_row;
            int s = l;
            if(s == 8){
                new_col = c;
                new_row = r - 1;
            }else if(s == 6){
                new_col = c + 1;
                new_row = r;
            }else if(s == 4){
                new_col = c - 1;
                new_row = r;
            }else if(s == 2){
                new_col = c;
                new_row = r + 1;
            }

            int swa = t_arr[new_row][new_col];
            t_arr[new_row][new_col] = t_arr[r][c];
            t_arr[r][c] = swa;

            c = new_col;
            r = new_row;

            new_col = 0;
            new_row = 0;

        }else{
            printf("\n\n\t\tYou inserted Wrong number to move.\n\t\tplease enter right number for move.\n");
            system("PAUSE");
            z--;
        }

        z++;
    }
}
