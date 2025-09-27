#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100 // Max size operand or operator
#define NUMBER '0'

void push(double f);
double pop(void);
int getop(char s[]);

/* Reverse Polish calculator */

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];
    while ( ( type = getop(s) ) != EOF ) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push( pop() + pop() );
                break;
            case '*':
                push( pop() * pop() );
                break;
            case '-':
                op2 = pop();
                push( pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push( pop() / op2);
                } else {
                    printf("Error: division by 0 not supported");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

