#include "monty.h"

/**
 * processFile - this function handles the processing of files
 *
 * @stack: a pointer to the stack "stack_l"
 * @fn: this is the name of the file that is going to be
 * processed
 * @instructions: List of functions.
 *
 * Description: refer to the first commmented out line
 *
 * Return: Nada
 */
void processFile(stack_l **stack, const char *fn, instruction_t instructions[])
{
	FILE *montyFile;

	montyFile = fopen(fn, "r");
	if (montyFile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fn);
		exit(EXIT_FAILURE);
	}
	eI(stack, montyFile, instructions);
	fclose(montyFile);
}

/**
 * eI - this function executes instructions
 *
 * @stack: a pointer to the stack "stack_l"
 * @montyFile: this is the a pointer to the monty file if the name
 * was not descriptive enough
 * @instructions: List of functions.
 *
 * Description: refer to the first commmented out line
 *
 * Return: Nada
 */
void eI(stack_l **stack, FILE *montyFile, instruction_t instructions[])
{
	char aLineInMonty[BUFSIZ];
	unsigned int line_number;
	char *opcode;
	int i;

	line_number = 0;
	while (fgets(aLineInMonty, sizeof(aLineInMonty), montyFile) != NULL)
	{
		line_number++;
		if (aLineInTheMontyFile[0] == '#')
		{
			continue;
		}
		opcode = strtok(aLineInMonty, " \n");
		if (opcode != NULL)
		{
			i = 0;
			while (instructions[i].opcode != NULL)
			{
				if (strcmp(opcode, instructions[i].opcode) == 0)
				{
					instructions[i].f(stack, line_number);
					break;
				}
				i++;
			}
			if (instructions[i].opcode == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}
}
