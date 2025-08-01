#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "../src/detab_core.h"

void test_simple_tab() {
    char input[] = "ciao\ttest";
    char output[MAXLINE] = {0};
    
    detabString(input, output);
    assert(strcmp(output, "ciao    test") == 0);
    printf("Test passed\n");
}

int main() {
    printf("Running detab tests...\n");
    test_simple_tab();
    printf("All tests passed!\n");
    return 0;
}

