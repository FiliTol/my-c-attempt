#include <stdio.h>

int main(void){
    int i;
    int n = 10;
    for (i = 0; i < n; ++i ) {
        printf("%d\n", i);
        if (i == 5) {
            goto contento;
        }
    }
contento:
    printf("Really happy to have found the number %d\n", i);
    return 0;
}

