#include <stdio.h>
#define IN 1
#define OUT 0
#define MAXLINE 1000
#define THRESHOLD 80
#define NMAXLINES 10

/* Create a program that takes text lines and returns all the lines with more
 * than 80 characters.*/

void copy(int i, int lc, char currentLine[], char linesArray[][MAXLINE]);

int main(){
    
    int c, i, lc, state, llen, maxaon;
    char line[MAXLINE];
    char linesArray[NMAXLINES][MAXLINE];

    llen = 0;   /*Single line length*/
    maxaon = 0; /*Max line length as of now (cumulator)*/
    i = 0;      /*Character counter. Reset after new line is hit*/
    lc = 0;      /*Lines counter*/
    state = OUT;
    
    while((c = getchar()) != EOF){
        if (c == '\n' || llen == MAXLINE) {
            if (llen > THRESHOLD) {
                copy(i, lc, line, linesArray);
                ++lc;
            }
            i = llen = 0;
        } else {
            line[i] = c;
            ++i;
            ++llen;
        }
        ;
    };
    
    printf("Lines with more than %d characters are:\n", THRESHOLD);
    for (int w = 0; w <= lc; ++w) {
        printf("%s\n", linesArray[w]);
    }
    return 0;
}

/* Creates a copy of character array into an another array
 * Index is provided as argument*/

void copy(int i, int lc, char currentLine[], char linesArray[][MAXLINE]) {
    int max = i;
    while (i >= 0){
        linesArray[lc][i] = currentLine[i];
        currentLine[i] = '\0';
        --i;
    };
    linesArray[lc][max+1] = '\0';
}












