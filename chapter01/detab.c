#include <stdio.h>
#include <string.h>
#define IN 1
#define OUT 0
#define TABSPACES 4
#define MAXLINE 1000
#define NMAXLINES 10

/* Create a program that takes text lines and returns all the lines with 
 * spaces in place of tabs. The goal is to use spaces to reach the next tab
 * stop.*/

void copy(int i, int lc, char currentLine[], char linesArray[][MAXLINE]);
void detabString(char currentLine[], char detabbedLine[]);
void repeatCharacter(int n, char character, char charactersArray[MAXLINE]);
void attachStrings(char leftString[MAXLINE], char rightString[MAXLINE]);

int main(){
    int c, i, lc, state, llen, maxaon;
    char line[MAXLINE];
    char linesArray[NMAXLINES][MAXLINE];

    llen = 0;   /*Single line length*/
    maxaon = 0; /*Max line length as of now (cumulator)*/
    i = 0;      /*Character counter. Reset after new line is hit*/
    lc = 0;     /*Lines counter*/
    state = OUT;
    
    while((c = getchar()) != EOF){
        if (c == '\n' || llen == MAXLINE) {
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
    char detabbedLine[MAXLINE];
    while (cnt < i){
        detabString(currentLine, detabbedLine);
        linesArray[lc][cnt] = detabbedLine[cnt];
        ++cnt;
    };
    linesArray[lc][i+1] = '\0';
}

void detabString(char currentLine[], char detabbedLine[]) {
    /* Take the current string and the string to fill in
     * Scans the string looking for tab characters
     * If tab is found, calculate the position of the tab character in the string
     * and substitute to the tab spaces (4-remainder spaces)
     * Substituting means adding these spaces to the final string instead
     * of the tab character*/
    int i, destinationIndex = 0;
    char spacesArray[MAXLINE];
    while (i < strlen(currentLine)) {
        if (currentLine[i] == '\t') {
            int n_spaces = (i - 1 + TABSPACES) % TABSPACES;
            char space = ' ';
            repeatCharacter(n_spaces, space, spacesArray);
            attachStrings(detabbedLine, spacesArray);
            /*detabbedLine[destinationIndex] = spacesArray;*/
            destinationIndex = destinationIndex + n_spaces;
        } else {
            detabbedLine[i] = currentLine[i];
            ++destinationIndex;
        }
        ++i;
    }
}

void repeatCharacter(int n, char character, char charactersArray[MAXLINE]) {
    /* Repeat the provided character n times*/
    int i = 0;
    while (i < n){
        charactersArray[i] = character;
        ++i;
    }
}

void attachStrings(char leftString[MAXLINE], char rightString[MAXLINE]){
    int i, finalStringLen;
    i = 0;
    finalStringLen = strlen(leftString);
    while (i < strlen(rightString)) {
        leftString[finalStringLen] = rightString[i];
        ++i;
    }
}

