#include "monty.h"

/**
 * main - this is the main function
 *
 * @ac: this is the number of comand line arguments that
 * have been submitted to the program
 * @av: this is a pointer to the array that holds the
 * command line arguments that have been inputted.
 *
 * Description: refer to the first commented out line
 *
 * Return: Always returns 0
 */

int main(int ac, char *av[])
{
	stack_l *stack;
	instruction_t instructions[] = {
		{"push", pushNewNode},
		{"pall", printerythang},
		{"pop", getRecked},
		{"pint", iAmTheTopG},
		{"swap", switcheroo},
		{"add", weTheTopTwo},
		{"nop", iAmaUselessPieceOfS___},
		{"mul", iWantMore},
		{"div", chopItUp},
		{NULL, NULL}};

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s filename\n", av[0]);
		exit(EXIT_FAILURE);
	}

	processFile(&stack, av[1], instructions);
	freestack(stack);
	return (0);
}

