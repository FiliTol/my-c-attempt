#include <stdio.h>

int bitCount(unsigned x);

int main(void) {
    int val = 12345;
    printf("The value %d contains %d 1 bits\n", val, bitCount(val));
    return 0;
}

// Count how many 1 bits are there in a provided input
// Note that declaring an unsigned argument explicitly will ensure that, when shifting
// to the right, each empty space will be filled with zeros instead of sign bits.
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

// x &= (x-1) --> x = x & (x-1)
// Faster Bitcount version
// This version is based on the principle that ANDing a number with its previous value
// will always remove the rightmost 1-bit from the AND operation result.
// This happens because given an X value (ex 1100) its previous value x-1 is,
// following the example, 1011. You get the -1 value by flipping to zero the rightmost
// 1-bit and turning all the following bits to 1.
// Given this transformation, when you AND this value with the original, all the
// bits from that flipped 1 bit - and on to the right - will not satisfy the AND
// condition, thus transforming the binary result into a number with the rightmost
// bit removed.
// This operation is carried on as long as the number does not fall to zero, that
// is when the last rightmost 1 bit is the last 1 bit left to flip.
// When that is finally flipped, the while condition gets unmatched and the loop stops,
// returning the accumulator up to that point.

int fasterBitCount(unsigned x) {
    int counter = 0;
    while (x != 0){
        x &= (x-1);
        ++counter;
    }
    return counter;
}

