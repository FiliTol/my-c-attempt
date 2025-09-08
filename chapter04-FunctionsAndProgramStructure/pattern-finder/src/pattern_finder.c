#include <stdio.h>
#include <string.h>
#include "pattern_finder_core.h"

char pattern[] = "ai";

int main(void){
    int w_pattern = strlen(pattern);
    char line[MAXLINE];
    int found = 0;
    while ( my_getline(line, MAXLINE) < MAXLINE ) {
        int s_line = strlen(line);
        if (pattern_search(line, s_line, pattern, w_pattern) >= 0 ) {
            printf("%s", line);
            found++;
        }
        found++;
    }

    return 0;
}

