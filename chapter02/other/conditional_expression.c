#include <stdio.h>

//// The following code generates an error when compiled
//// The reason is simple: the const variable, once defined, is read only
//// and cannot be modified.

//int main(void) {
//    int a = 10;
//    int b = 17;
//    const int z = 0;
//    if (a > b){
//        z = a;
//    } else {
//        z = b;
//    }
//    printf("%d\n", z);
//    return 0;
//}

//// Conditional expressions represent a solution to the const dynamic definition
/*
int main(void) {
    int a = 10;
    int b = 17;
    const int z = (a > b) ? a : b;
    printf("%d\n", z);
    return 0;
}
*/

char lower(char a);

int main(void) {
    printf("%c\n", lower('B'));
    return 0;
}

/* OLD VERSION: convert c to lower case; ASCII only
int lower(int c)
{
if (c >= 'A' && c <= 'Z') {
    return c + 'a' - 'A';
} else {
    return c
};
}
*/

char lower(char a) {
    return (a >= 'A' && a <= 'Z') ? (a + 'a' - 'A') : a;
}

