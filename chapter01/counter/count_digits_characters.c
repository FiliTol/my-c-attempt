#include <stdio.h>

int main() {
    
    int c, i, nwhite, nother;
    int ndigit[10];

    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0;
    }

    while ( (c = getchar()) != EOF ) {
        switch (c) {
            case '\n':
                ++nwhite;
                break;
            case '\t':
                ++nwhite;
                break;
            case ' ':
                ++nwhite;
                break;
            case '0' ... '9':
                ++ndigit[c - '0'];
                break;
            default:
                ++nother;
        }
    }
    printf("digits =");
    for (i = 0; i < 10; ++i) {
        printf(" %d", ndigit[i]);
    }
    printf(" white characters =%d, other characters =%d\n", nwhite, nother);

    return 0;
}

