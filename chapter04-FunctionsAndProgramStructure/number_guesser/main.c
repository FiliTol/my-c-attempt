#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXNUMSIZE 100

// Stack related objects
void push(int num);
int pop(void);

int input[MAXNUMSIZE];
int stack_position = 0;

// Functions for game logic
int generate_random_number(void);
void manual_scanf(void);
int get_number(void);
int evaluate_number(int proxy);
void game(void);

int pow_fn(int base, int power);


int main(void)
{
    char command;
    do {
        game();
        printf("Play again? (Y/N) ");
        scanf(" %c", &command);
    } while (command == 'y' || command == 'Y');
    return 0;
}

int pow_fn(int base, int power)
{
	int i;
	int ris = 1;
	for (i = 0; i < power; i++) {
		ris = ris * base;
	}
	return ris;
}

void game(void)
{
	int rand_num = generate_random_number();
	printf("A new number has been chosen\n");
	int ris;
	int i = 0;
	while ((ris = evaluate_number(rand_num)) != 1)
	{
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
	if(stack_position == 0) {
		printf("Stack is empty!\n");
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
		int ris = c - '0';
		push(ris);
	}
}

int get_number(void)
{
	printf("\nEnter guess: ");
	manual_scanf();
	int i = 0;
	int given = 0;
	while(stack_position > 0) {
		given = given + pop()*pow_fn(10, i++);
	}
	return given;
}

int evaluate_number(int proxy)
{
	int ris = get_number();
	if (ris == proxy) {
		printf("\nYou won!\n");
		return 1;
	}
	if (ris > proxy) {
		printf("\nToo high, try again");
	} else {
		printf("\nToo low, try again");
	}
	return 0;
}

