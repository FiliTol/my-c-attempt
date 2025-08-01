#include <stdio.h>

int main() {
    int c, i, bar, height, nchars;
    nchars = 127;
    int frequencies[nchars];

    for (i = 0; i < nchars; ++i) {
        frequencies[i] = 0;
    }

    while ( (c = getchar()) != EOF ) {
        ++frequencies[c - '0'];
        }
    for ( bar = 0; bar < nchars; ++bar ) {
        printf("%c: ", bar + '0');
        for (height = 0; height < frequencies[bar]; ++height) {
            printf("]");
        }
        printf("\n");
    }
    return 0;
}

