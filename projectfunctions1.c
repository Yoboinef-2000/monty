#include "monty.h"

/**
 * pushNewNode - this function pushes a new node to the stack stack_s
 *
 * @stack: a pointer to the stack "stack_l"
 * @line_number: this is the the line number if the naming was not
 * descriptive enough
 *
 * Description: refer to the first commmented out line
 *
 * Return: Nada
 */
void pushNewNode(stack_l **stack, unsigned int line_number)
{
	char *ar;
	int value;
	stack_l *newnode;

	ar = strtok(NULL, " \n");
	if ((ar == NULL || !isdigit(*ar)) && ((*ar != '-' && !isdigit(*(ar + 1)))))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(ar);
	newnode = malloc(sizeof(stack_l));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->n = value;
	newnode->prev = NULL;
	newnode->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = newnode;
	}
	*stack = newnode;
}

/**
 * printerythang - this function print every element in the stack stack_s
 *
 * @stack: a pointer to the stack "stack_l"
 * @line_number: this is the the line number if the naming was not
 * descriptive enough
 *
 * Description: refer to the first commmented out line
 *
 * Return: Nada
 */
void printerythang(stack_l **stack, unsigned int line_number)
{
	stack_l *currentnode;

	(void)line_number;

	currentnode = *stack;
	while (currentnode != NULL)
	{
		printf("%d\n", currentnode->n);
		currentnode = currentnode->next;
	}
}

/**
 * iAmTheTopG - this function prints the value at the top of
 * the stack, followed by a new line.
 *
 * @stack: a pointer to the stack "stack_l"
 * @line_number: this is the the line number if the naming was not
 * descriptive enough
 *
 * Description: refer to the first commmented out line
 *
 * Return: Nada
 */
void iAmTheTopG(stack_l **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * switcheroo - this function swaps the top two elements of the stack.
 *
 * @stack: a pointer to the stack "stack_l"
 * @line_number: this is the the line number if the naming was not
 * descriptive enough
 *
 * Description: refer to the first commmented out line
 *
 * Return: Nada
 */
void switcheroo(stack_l **stack, unsigned int line_number)
{
	stack_l *holder;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	holder = (*stack)->next;
	(*stack)->next = holder->next;
	holder->next = *stack;
	holder->prev = NULL;

	if ((*stack)->next != NULL)
	{
		(*stack)->next->prev = *stack;
	}
	*stack = holder;
}

/**
 * weTheTopTwo - this function adds the top two elements of the stack.
 *
 * @stack: a pointer to the stack "stack_l"
 * @line_number: this is the the line number if the naming was not
 * descriptive enough
 *
 * Description: refer to the first commmented out line
 *
 * Return: Nada
 */
void weTheTopTwo(stack_l **stack, unsigned int line_number)
{
	stack_l *holder;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	holder = *stack;
	*stack = (*stack)->next;
	free(holder);

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
}
