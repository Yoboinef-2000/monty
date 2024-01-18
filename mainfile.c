#include "stque.h"

/*
 * main - this is the main fucntion
 *
 * @ac: this is the number of comand line arguments that
 * have been submitted to the program
 * @av: this is a pointer to the array that holds the
 * command line arguments that have been inputted.
 *
 * Description: refere to the first commented out line
 *
 * Return: Always returns 0
 */

/*int main(int ac, char *av[])
{
    stack_l *stack; 
    FILE *montyFile;
    char *aLineInTheMontyFile;
    size_t len;
    ssize_t read;
    unsigned int line_number;
    char *opcode;
    int i;
    instruction_t instructions[] = {
        {"push", pushNewNode},
        {"pall", printerythang},
        {NULL, NULL}};

    stack = NULL;
    if (ac != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", av[0]);
        exit(EXIT_FAILURE);
    }
    montyFile = fopen(av[1], "r");
    if (montyFile == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }
    aLineInTheMontyFile = NULL;
    len = 0;
    line_number = 0;
    while ((read = getline(&aLineInTheMontyFile, &len, montyFile)) != -1)
    {
        line_number++;
        opcode = strtok(aLineInTheMontyFile, " \n");
        if (opcode != NULL)
        {
            i = 0;
            while (instructions[i].opcode != NULL)
            {
                if (strcmp(opcode, instructions[i].opcode) == 0)
                {
                    instructions[i].f(&stack, line_number);
                    break;
                }
                i++;
            }
        }
    }
    free(aLineInTheMontyFile);
    fclose(montyFile);
    return 0;
}
*/

int main(int ac, char *av[])
{
    stack_l *stack; 
    FILE *montyFile;
    char aLineInTheMontyFile[BUFSIZ];
    unsigned int line_number;
    char *opcode;
    int i;
    instruction_t instructions[] = {
        {"push", pushNewNode},
        {"pall", printerythang},
        {NULL, NULL}};

    stack = NULL;
    if (ac != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", av[0]);
        exit(EXIT_FAILURE);
    }
    montyFile = fopen(av[1], "r");
    if (montyFile == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }
    
    line_number = 0;
    while (fgets(aLineInTheMontyFile, sizeof(aLineInTheMontyFile), montyFile) != NULL)
    {
        line_number++;
        opcode = strtok(aLineInTheMontyFile, " \n");
        if (opcode != NULL)
        {
            i = 0;
            while (instructions[i].opcode != NULL)
            {
                if (strcmp(opcode, instructions[i].opcode) == 0)
                {
                    instructions[i].f(&stack, line_number);
                    break;
                }
                i++;
            }
        }
    }
    fclose(montyFile);
    return 0;
}


