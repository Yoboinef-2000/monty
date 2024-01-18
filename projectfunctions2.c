#include "monty.h"

/**
 * getRecked - this function removes the top element of the stack.
 *
 * @stack: a pointer to the stack "stack_l"
 * @line_number: this is the the line number if the naming was not
 * descriptive enough
 *
 * Description: refer to the first commmented out line
 *
 * Return: Nada
 */
void getRecked(stack_l **stack, unsigned int line_number)
{
	stack_l *holder;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	holder = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(holder);
}

/**
 * iAmaUselessPieceOfS___ - this function does nothing.
 * It just likes sleeping all day. Might as well change
 * the function name to my name.
 *
 * @stack: a pointer to the stack "stack_l"
 * @line_number: this is the the line number if the naming was not
 * descriptive enough
 *
 * Description: refer to the first commmented out line
 *
 * Return: Nada
 */
void iAmaUselessPieceOfS___(stack_l **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * iWantMore - this function multiplies the second top element
 * of the stack with the top element of the stack.
 *
 * @stack: a pointer to the stack "stack_l"
 * @line_number: this is the the line number if the naming was not
 * descriptive enough
 *
 * Description: refer to the first commmented out line
 *
 * Return: Nada
 */
void iWantMore(stack_l **stack, unsigned int line_number)
{
	stack_l *holder;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	holder = *stack;
	*stack = (*stack)->next;
	free(holder);

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
}

/**
 * chopItUp - this function divides the second top element
 * of the stack by the top element of the stack.
 *
 * @stack: a pointer to the stack "stack_l"
 * @line_number: this is the the line number if the naming was not
 * descriptive enough
 *
 * Description: refer to the first commmented out line
 *
 * Return: Nada
 */
void chopItUp(stack_l **stack, unsigned int line_number)
{
	stack_l *holder;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	holder = *stack;
	*stack = (*stack)->next;
	free(holder);

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
}

/**
 * freestack - this function frees a doubly linked list
 *
 * @head: this is a pointer to the doubly linked list that is
 * going to be freed
 *
 * Description: refer to the first commented out line
 *
 * Return: nada
 */
void freestack(stack_l *head)
{
	stack_l *currentnode;

	while (head != NULL)
	{
		currentnode = head;
		head = head->next;
		free(currentnode);
	}
}
