#include <stdio.h>

int main(){
    long nc;

    for (nc = 0; getchar() != EOF; ++nc);
    /* nc =0;
    while (getchar() != EOF) {
        ++nc;
    };*/
    printf("%ld\n", nc);
    return 0;
};

