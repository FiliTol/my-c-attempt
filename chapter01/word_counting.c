#include <stdio.h>

#define IN  1
#define OUT 0

/* Count words, lines and characters in input*/

int main() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    
    while ((c = getchar()) != EOF) {
        ++nc;
        if( c == '\n' ) {
            ++nl;
        };
        if( c == '\n' || c == '\t' || c == ' ') {
            state = OUT;
        } else if ( state == OUT ) {
            state = IN;
            ++nw;
        }
    }
    printf("Characters: %d, lines: %d, words: %d\n", nc, nl, nw);
    return 0;
}

