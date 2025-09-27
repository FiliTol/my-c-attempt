#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXNUMSIZE 100

// Stack related objects
void push(int num);
int pop(void);

char input[MAXNUMSIZE];
int stack_position = 0;

// Functions for game logic
int generate_random_number(void);
void manual_scanf(void);
int get_number(void);
int evaluate_number(void);
void game(void);


int main(void)
{
    char command;
    do {
        game();
        printf("Play again? (Y/N) ");
        scanf(" %c\n", &command);
    } while (command == 'y' || command == 'Y');
    return 0;
}


// A single Game is composed of:
// - generate random number
// - then loop:
//    - get users number
//    - evaluate two numbers
//    - return the result of evaluation
// - Once game finished, ask to replay

void game(void)
{
    printf("A new number has been chosen.");
    int ris;
    int i = 0;
    while ((ris = evaluate_number()) != 1)
    {
        printf("\nEnter guess: ");
        ++i;
    }
    printf("You won in %d guesses!\n", i);
}

int generate_random_number(void)
{   
    srand(time(NULL));
    return rand() % MAXNUMSIZE + 1;
}

void push(int num)
{
    if(stack_position < MAXNUMSIZE) {
        input[stack_position++] = num;
    } else {
        printf("Stack is full! Cannot push to stack.");
    }
}

int pop(void)
{
    if(stack_position == 0){
        printf("Stack is empty");
        return -1;
    } else {
        return input[--stack_position];
    }
}

void manual_scanf(void)
{
    int c;
    while((c = getchar()) != EOF && c != '\n')
    {
        push(c);
    }
}

int get_number(void)
{   
    manual_scanf();
    int i = 0;
    int given = 0;
    while(stack_position >= 0){
        given = given + pop()*(10^i++);
    }
    return given;
}

int evaluate_number(void)
{
    int ris = get_number();
    int rand_num = generate_random_number();
    if (ris == rand_num){
        printf("You won");
        return 1;
    }
    if (ris > rand_num) {
        printf("Too high, try again");
    } else {
        printf("Too low, try again");
    }
    return 0;
}








