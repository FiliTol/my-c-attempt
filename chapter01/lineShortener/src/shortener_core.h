#ifndef DETAB_CORE_H
#define DETAB_CORE_H

#define TABSPACES 8
#define MAXLENGTHLINE 1000
#define COLUMNSMAX 10

int floorDivision(int num, int denom);
int getCurrentLimit(int position);
void copy(char currentLine[], char linesArray[MAXLENGTHLINE]);
void copyReplaceCharacter(char sourceString[MAXLENGTHLINE], char destString[MAXLENGTHLINE], int position, char charToFind, char charToInsert);
int findLastOccurrence(int limit, char charToFind, char stringToSearch[MAXLENGTHLINE]);
void generateArrayOfOccurrences(char charToFind, char stringToSearch[MAXLENGTHLINE], int occurrencesArray[COLUMNSMAX]);

#endif
