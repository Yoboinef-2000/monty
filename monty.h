#ifndef STQUE_H
#define STQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_l;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_l **stack, unsigned int line_number);
} instruction_t;

void pushNewNode(stack_l **stack, unsigned int line_number);
void printerythang(stack_l **stack, unsigned int line_number);
void iAmTheTopG(stack_l **stack, unsigned int line_number);
void getRecked(stack_l **stack, unsigned int line_number);
void switcheroo(stack_l **stack, unsigned int line_number);
void weTheTopTwo(stack_l **stack, unsigned int line_number);
void cutIt(stack_l **stack, unsigned int line_number);
void iAmaUselessPieceOfS___(stack_l **stack, unsigned int line_number);
void iWantMore(stack_l **stack, unsigned int line_number);
void chopItUp(stack_l **stack, unsigned int line_number);
void weirdDivision(stack_l **stack, unsigned int line_number);
void freestack(stack_l *head);
void processFile(stack_l **stack, const char *fn, instruction_t instructions[]);
void eI(stack_l **stack, FILE *montyFile, instruction_t instructions[]);

#endif /* STQUE_H */

