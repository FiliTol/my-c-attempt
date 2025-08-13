#include <string.h>
#include "shortener_core.h"

#define WRAPCOLUMN 80
#define COLUMNSMAX 10
#define MAXLENGTHLINE 1000


int floorDivision(int num, int denom){
    double div = num/denom;
    int result = div;
    return result;
}

/* Creates a copy of character array into an another array
 * Index is provided as argument*/
void copy(char currentLine[], char linesArray[MAXLENGTHLINE])
{
    int index;
    index = 0;
    while (currentLine[index] != '\0'){
        linesArray[index] = currentLine[index];
        ++index;
    };
}

/* Function that based on the current position in a string returns the next limit
 * to consider for the text wrapping*/
int getCurrentLimit(int position) {
    int div, result;

    div = floorDivision(position, WRAPCOLUMN);
    result = (div + 1) * WRAPCOLUMN;

    return result;
}

/* Function that takes a string and replaces the character ToFind with the character ToInsert
 * The goal is to make this function interact with the findLastOccurence function to replace
 * only a specific occurrence of the character*/
void copyReplaceCharacter(
        char sourceString[MAXLENGTHLINE],
        char destString[MAXLENGTHLINE],
        int position,
        char charToFind,
        char charToInsert
)
{
    //int index, limit; /*index of the character to replace*/
    int element;
    int occurrences[COLUMNSMAX];
    //limit = getCurrentLimit(position);
    //index = findLastOccurrence(limit, charToFind, sourceString);
    copy(sourceString, destString);
    generateArrayOfOccurrences(charToFind, sourceString, occurrences);
    for (element = 0; element < COLUMNSMAX; ++element) {
        destString[occurrences[element]] = charToInsert;
    }
}


/* Function that takes a string, a character to find and a limit of characters to use as a
 * multiplier and limit. The returned int is the index of the last occurrence of the charToFind
 * before the limit*/
int findLastOccurrence(int limit, char charToFind, char stringToSearch[MAXLENGTHLINE])
{
    int index, saveBest;
    saveBest = 0;
    for (index = 0; index < limit; ++index) {
        if (stringToSearch[index] == charToFind) {
            saveBest = index;
        }
    }
    return saveBest;
}

/* Function that returns an array of integers that are the indexes of characters
 * to substituted in the process. Characters to substitute are computed using
 * the last occurence logic of the findLastOccurrence function*/
void generateArrayOfOccurrences(
        char charToFind,
        char stringToSearch[MAXLENGTHLINE],
        int occurrencesArray[COLUMNSMAX])
{
    int multiples[COLUMNSMAX];
    int counter;
    for (counter = 0; counter < COLUMNSMAX; ++counter) {
        multiples[counter] = WRAPCOLUMN * (counter + 1);
        occurrencesArray[counter] = findLastOccurrence(multiples[counter], charToFind, stringToSearch);
    }
}
