// Create a script that scans a text and if it finds a specific pattern it prints
// the line containing the pattern.

#include "pattern_finder_core.h"
#include <string.h>

#define MAXLINE 1000 // maximum input line

int my_getline(char s[], int max_chars)
{
    int i = 0;
    int c;
    while ( i < max_chars ) {
        c = getchar();
        if ( c == EOF ){
            break;
        }
        if ( c == '\n' ) {
            s[i] = c;
            ++i;
            break;
        }
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int pattern_search(char s[], int s_size, char wanted[], int w_size) {
    int i = 0;
    int status = 0;

    while (i  < s_size) {
        if (s[i] == wanted[0]) {
            int ci = i;
            int j = 0;
            while (j < w_size){
                if (s[ci] == wanted[j]) {
                    ++status;
                }
                ++ci;
                ++j;
            }
            if (status == w_size)
                return i;
        }
        ++i;
    }
    return -1;
}

