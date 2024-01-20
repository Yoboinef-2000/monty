#include "monty.h"

/**
 * cutIt - this function subtracts the top element of the stack
 * from the second top element of the stack.
 *
 * @stack: a pointer to the stack "stack_l"
 * @line_number: this is the the line number if the naming was not
 * descriptive enough
 *
 * Description: refer to the first commmented out line
 *
 * Return: Nada
 */
void cutIt(stack_l **stack, unsigned int line_number)
{
	stack_l *holder;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;

	holder = *stack;
	*stack = (*stack)->next;
	free(holder);
}
