#include <stdio.h>

#define MAXVAL 100 // Max size of stack

int sp = 0;
double stack[MAXVAL];

void push(double f);
double pop(void);

// Function that pushes the argument to the stack
void push(double f) 
{
    if (sp < MAXVAL) {
        stack[sp++] = f;
    } else {
        printf("Stack is full, can't push new values");
    }
}

// Function that pops the argument from the stack and returns it
double pop(void)
{
    if (sp > 0) {
        return stack[--sp];
    } else {
        printf("Stack empty");
        return 0.0;
    }
}

