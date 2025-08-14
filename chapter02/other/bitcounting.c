#include <stdio.h>

int bitCount(unsigned x);

int main(void) {
    int val = 12345;
    printf("The value %d contains %d 1 bits\n", val, bitCount(val));
    return 0;
}

// Count how many 1 bits are there in a provided input
int bitCount(unsigned x) {
    int b = 0;
    while (x != 0){
        if (x & 1) {
            b += 1;
        }
        x >>= 1;
    }
    return b;
}

