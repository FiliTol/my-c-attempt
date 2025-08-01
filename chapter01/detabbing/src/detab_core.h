#ifndef DETAB_CORE_H
#define DETAB_CORE_H

#define TABSPACES 8
#define MAXLINE 1000

void detabString(char currentLine[], char detabbedLine[]);
void repeatCharacter(int n, char character, char charactersArray[MAXLINE]);
void attachStrings(char leftString[MAXLINE], char rightString[MAXLINE]);

#endif
