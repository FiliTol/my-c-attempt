#include <stdio.h>

#define STACKSIZE 100

void push(int element);
int pop(void);

int contents[STACKSIZE];
int top;

int main(void)
{
    return 0;
}

void push(int element)
{
    if(top < STACKSIZE){
        contents[top++] = element;
    } else {
        printf("Stack is full. Cannot add element to stack");
    }
}

int pop(void)
{
    if(top > 0){
        return contents[--top];
    } else {
        printf("Stack is empty");
        return -1;
    }
}

