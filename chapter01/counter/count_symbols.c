#include <stdio.h>


int main(){
    int c, tab, newline, blank;
    
    tab = 0;
    newline = 0;
    blank = 0;
    while((c = getchar()) != EOF) {
        switch(c){
            case '\t':
                ++tab;
                break;
            case '\n':
                ++newline;
                break;
            case ' ':
                ++newline;
                break;
        }
    };
    printf("Tabs: %d, Newlines: %d, Blanks: %d\n", tab, newline, blank);
    return 0;
};

