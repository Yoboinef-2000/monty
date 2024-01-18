#include "monty.h"

/**
 * pushNewNode - this function pushes a new node to the stack stack_s
 * 
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
    char *arg;
    int value;
    stack_l *newnode;

    arg = strtok(NULL, " \n");
    if ((arg == NULL || !isdigit(*arg)) && ((*arg != '-' && !isdigit(*(arg + 1)))))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);
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
        (*stack)->prev = newnode;

    *stack = newnode;
}

/**
 * printerythang - this function print every element in the stack stack_s
 * 
 * @head: a pointer to the stack "stack_l"
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

