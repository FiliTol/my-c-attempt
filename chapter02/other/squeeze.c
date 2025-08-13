#include <stdio.h>
#include <string.h>

void squeezeMore(char s1[], char s2[], char final[]);
int isContainedIn(char c, char str[]);

int main()
{
    char final[100];
    squeezeMore("Testing", "testin", final);
    printf("%s\n", final);
    return 0;
}

void squeezeMore(char s1[], char s2[], char final[])
{
    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++) {
        if (isContainedIn(s1[i], s2) != 1) {
            final[j++] = s1[i];
        }
    }
    final[j] = '\0';
}

int isContainedIn(char c, char str[]) {
    int i = 0; // index
    while (i < strlen(str)) {
        if (str[i] == c) {
            return 1;
        }
        ++i;
    }
    return 0;
}

