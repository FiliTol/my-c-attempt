#include <stdio.h>

int isEven(int n);
int timesEight(int n);
int bitValue(int n_th, int n);
int binaryTableMultiplication(unsigned int u, unsigned int d);
int nTimesM(int n, int m);

int main(){
    // printf("%d\n", isEven(345679));
    printf("%d\n", nTimesM(15, 345671));
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
/// The following method is called Russian Peasant algorithm
int nTimesM(int n, int m) {
    if (n == 0 || m == 0) {
        return 0;
    } else {
        int result = 0;
        while (m > 0) {
            if (m & 1) {
                result += n;
            }
            n <<= 1;
            m >>= 1;
        }
        return result;
    }
}

