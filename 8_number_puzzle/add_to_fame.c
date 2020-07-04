#include "add_to_fame.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void add_to_fame(){
    getchar();
    printf("\n\t\tPlease add your signature dialogue and your name to 'HALL OF FAME'.\n\n");
    printf("\n\t\tExample: 'I was born to be a champion', Aurther.\n\n");
    char st[150];
    char st1[150] = "\n";
    gets(st);
    strcat(st1, st);


    FILE *data;
    data = fopen("Hall_of_fame.txt", "a");

    fprintf(data, st1);

    fclose(data);
}

