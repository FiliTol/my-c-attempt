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
int main(void) {
    int a = 10;
    int b = 17;
    const int z = (a > b) ? a : b;
    printf("%d\n", z);
    return 0;
}

