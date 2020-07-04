#include "Hall_of_fame.h"

#include<stdio.h>
#include<stdlib.h>


void fame(){
    FILE *data;

    data = fopen("Hall_of_fame.txt", "r");
    char single_line[150];

    int i = 1;
    while(!feof(data)){
        fgets(single_line, 150, data);
        printf("%d. ", i);
        puts(single_line);
        i++;
    }

    fclose(data);
}
