#include <stdio.h>

int isEven(int n);
int timesEight(int n);
int bitValue(int n_th, int n);
int nTimesM(int n, int m);

int main(){
    // printf("%d\n", isEven(345679));
    printf("%d\n", timesEight(5));
    return 0;
}

// Returns 1 if the number is even
int isEven(int n) {
    return !(n & 1);
}

// Multiplies the argument by 8 by using bit shifting
int timesEight(int n) {
    return n << 3;
}

//// Generalize multiplication operation by using bitwise operators
// Extract value of specific bit
int bitValue(unsigned int n_th, unsigned int n) {
    unsigned int mask = 1 << n_th;
    return (n & mask) >> n_th;
}

// Generalize multiplication using bitwise operations
int nTimesM(int n, int m) {
    return 0;
}
