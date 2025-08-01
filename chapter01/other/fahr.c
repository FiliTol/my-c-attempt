#include <stdio.h>

int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("| Fahrenheit\t | \tCelsius |\n");
    printf("---------------------\n");
    while (fahr <= upper){
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("| %3.0f\t | \t %6.1f|\n", fahr, celsius);
        fahr = fahr + step;
        printf("-----------------\n");
    };
    return 0;
};

