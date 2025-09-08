
#ifndef PATTERN_FINDER_CORE_H
#define PATTERN_FINDER_CORE_H

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 // maximum input line

int my_getline(char s[], int max_chars);
int pattern_search(char s[], int s_size, char wanted[], int w_size);

#endif

