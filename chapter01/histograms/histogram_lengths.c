#include <stdio.h>

#define IN 1
#define OUT 0


int main() {
    /*
     * Histogram of lengths of words in input
     * Store data in an array. Every slot in the array is a number of characters
     * in the word. The cardinality of each number in the array represents the
     * frequency of that number of characters (the index) in the given input.
    */
    int c, bar, i, height, nwords, wchars;
    nwords = 10;
    wchars = 0;
    int frequencies[10];

    for (i = 0; i < nwords; ++i) {
        frequencies[i] = 0;
    }

    while ( (c = getchar()) != EOF ) {
        if (c == '\n' || c == '\t' || c == ' ') {
            ++frequencies[wchars];
            wchars = 0;
        } else {
            ++wchars;
        }
    }
    for ( bar = 0; bar < nwords; ++bar ) {
        for (height = 0; height < frequencies[bar]; ++height) {
            printf("-");
        }
        printf("\n");
    }
    return 0;
}

