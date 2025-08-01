#include <string.h>
#include "detab_core.h"


void detabString(char currentLine[], char detabbedLine[]) {
    /* Take the current string and the string to fill in
     * Scans the string looking for tab characters
     * If tab is found, calculate the position of the tab character in the string
     * and substitute to the tab spaces (4-remainder spaces)
     * Substituting means adding these spaces to the final string instead
     * of the tab character*/
    int i, destinationIndex;
    i = destinationIndex = 0;
    char spacesArray[MAXLINE] = {0};
    while (i < strlen(currentLine)) {
        if (currentLine[i] == '\t') {
            int n_spaces = TABSPACES - (destinationIndex % TABSPACES);
            char space = ' ';
            repeatCharacter(n_spaces, space, spacesArray);
            attachStrings(detabbedLine, spacesArray);
            destinationIndex = destinationIndex + n_spaces;
        } else {
            detabbedLine[destinationIndex] = currentLine[i];
            ++destinationIndex;
        }
        ++i;
    }
    detabbedLine[destinationIndex] = '\0';
}

void repeatCharacter(int n, char character, char charactersArray[MAXLINE]) {
    /* Repeat the provided character n times*/
    int i = 0;
    while (i < n){
        charactersArray[i] = character;
        ++i;
    }
    charactersArray[i] = '\0';
}

void attachStrings(char leftString[MAXLINE], char rightString[MAXLINE]){
    int i, leftStringLen, rightStringLen;
    i = 0;
    leftStringLen = strlen(leftString);
    rightStringLen = strlen(rightString);
    while (i < rightStringLen) {
        leftString[leftStringLen] = rightString[i];
        ++i;
        ++leftStringLen;
    }
}

