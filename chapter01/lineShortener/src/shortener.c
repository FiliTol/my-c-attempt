#include <stdio.h>
#include <string.h>
#include "shortener_core.h"

#define MAXLENGTHLINE 1000

/* Create a program that folds input lines given a fixed length, on their
 * last blank character before the fixed column number.*/

/* - Take input from the buffer
 * - Once a new column character is found, a function proceeds to copy the line
 *   and add in the proper place the newline \n. 
 * - Once the new string with newlines inside is created, this is copied in the
 *   lines array
 * - the lines array is printed
 *
 * Note that inserting newline characters is a quicker solution to the linesArray
 * issue implemented in the detabber program*/

int main(){
    int c, index;
    char toFind, toInsert;
    toFind = ' ';
    toInsert = '\n';
    char currentLine[MAXLENGTHLINE];
    char lineToPrint[MAXLENGTHLINE];

    index = 0;      /*Character counter. Reset after new line is hit*/
    
    while((c = getchar()) != EOF){
        currentLine[index] = c;
        ++index;
    }
    currentLine[index] = '\0';
    for (index = 0; index < strlen(currentLine); ++index) {
        copyReplaceCharacter(currentLine, lineToPrint, index, toFind, toInsert);
    }

    printf("--------------------------------------------------\n");
    printf("Lines:\n%s", lineToPrint);
    return 0;
}

