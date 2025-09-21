#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'
#define BUFFERSIZE 100

int getch(void);
void ungetch(int);

// Get next character or numeric operand
// This function shall return a value that represents if the value in the input
// is a number or not.
// For this purpose, spaces and tabs shall be skipped
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    if (!isdigit(c) && c != '.') {
        s[1] = '\0';
        return c;
    }
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()));
    }

    s[i] = '\0';
    if ( c != EOF ) {
        ungetch(c);
    }
    return NUMBER;
}

int getch(void) {

}



void ungetch(int);
