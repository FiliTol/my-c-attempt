#include <stdio.h>

int main(void)
{
    int i = 0;
    char s[100];
    char c;
    int lim = 100;
    if (i < lim-1) {
        if ((c=getchar()) != '\n') {
            if (c != EOF) {
                s[i] = c;
                ++i;
            }
        }
    }
}

