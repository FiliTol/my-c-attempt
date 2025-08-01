#include <stdio.h>
#include "detab_core.h"

#define NMAXLINES 10

/* Create a program that takes text lines and returns all the lines with 
 * spaces in place of tabs. The goal is to use spaces to reach the next tab
 * stop.*/

void copy(int i, int lc, char currentLine[], char linesArray[][MAXLINE]);

int main(){
    int c, i, lc, state, llen, maxaon;
    char line[MAXLINE];
    char linesArray[NMAXLINES][MAXLINE];

    llen = 0;   /*Single line length*/
    maxaon = 0; /*Max line length as of now (cumulator)*/
    i = 0;      /*Character counter. Reset after new line is hit*/
    lc = 0;     /*Lines counter*/
    
    while((c = getchar()) != EOF){
        if (c == '\n' || llen == MAXLINE) {
            line[i] = '\0';
            copy(i, lc, line, linesArray);
            ++lc;
            i = llen = 0;
        } else {
            line[i] = c;
            ++i;
            ++llen;
        }
        ;
    };
    printf("--------------------------------------------------\n");
    printf("Lines:\n");
    for (int w = 0; w < lc; ++w) {
        printf("%s\n", linesArray[w]);
    }
    return 0;
}

/* Creates a copy of character array into an another array
 * Index is provided as argument*/

void copy(int i, int lc, char currentLine[], char linesArray[][MAXLINE]) {
    int cnt = 0;
    char detabbedLine[MAXLINE] = {0};
    detabString(currentLine, detabbedLine);
    while (detabbedLine[cnt] != '\0'){
        linesArray[lc][cnt] = detabbedLine[cnt];
        ++cnt;
    };
    linesArray[lc][cnt] = '\0';
}

