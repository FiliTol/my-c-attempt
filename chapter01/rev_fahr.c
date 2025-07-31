#include <stdio.h>

#define LOWER 0      /*Lower interval limit*/
#define UPPER 300    /*Upper interval limit*/
#define STEP 20      /*Step size*/

int main() {
    float fahr;

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP){
        printf("%3.1f\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    };
    return 0;
};

