#include <stdio.h>
#define IN 1
#define OUT 0
#define MAXLINE 1000

/* Create a program that takes text lines and return the longest one.*/

int maxaon;
char line[MAXLINE];
char longestline[MAXLINE];

void copy(int i, char currentLine[], char longestLine[]);

int main(){
    
    int c, i, state, llen;
    extern int maxaon;
    extern char line[];
    extern char longestline[];

    llen = 0;
    maxaon = 0;
    i = 0;
    state = OUT;
    
    while((c = getchar()) != EOF){
        if (c == '\n' || llen == MAXLINE) {
            if (llen > maxaon) {
                maxaon = llen;
                copy(i, line, longestline);
            }
            i = llen = 0;
        } else {
            line[i] = c;
            ++i;
            ++llen;
        }
        ;
    };
    
    printf("The longest line has %d characters\n", maxaon);
    printf("The longest line is\n");
    printf("%s\n", longestline);
    return 0;
}

/* Creates a copy of character array into an another array
 * Index is provided as argument*/

void copy(int i, char currentLine[], char longestLine[]) {
    int max = i;
    while (i >= 0){
        longestLine[i] = currentLine[i];
        currentLine[i] = '\0';
        --i;
    };
    longestLine[max+1] = '\0';
}












