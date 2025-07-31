#include <stdio.h>

/* The following is a function prototype and is used for various reasons, such as
 * - informing the interpreter about a function without defining it
 * - enabling the programmer to define the function after the main function
 * - defining 
 */

int power(int m, int n);

int main(){
    int i;

    /*printf("%d\n", power(2, 5));*/

    for (i = 0; i < 10; ++i){
        printf("%d, %d\n", i, power(10 - i, i));
    }
    return 0;
};

int power_first(int m, int n) {
    int p, i;
    p = 1;

    for (i = 1; i <= n; ++i) {
        p = p * m;
    };
    
    return p;
}

/* OR */

int power_second(int base, int n) {
    int p;
    
    for (p = 1; n > 0; --n){
        p = p * base;
    };
    return p;
};

int power(int base, int n) {
    int p = 1;
    
    while (n > 0){
        p = p * base;
        --n;
    };
    
    return p;
};
