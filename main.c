#include "monty.h"
#include "stdlib.h"
#include "stdio.h"
/**
 * main - entry point of the program
 * @argv: argument vector
 * @argc: argument count
 * Return: zero or one
 */

int main(int argc, char **argv)
{
	FILE *file;
	int value;
	char line[1024];
	char *opcode, *arg;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	} file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \n\t");
		arg = strtok(NULL, " \n\t");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			if (arg == NULL || !is_integer(arg))
			{
				printf("L%u: usage: push integer\n", line_number);
				fclose(file);
				return (EXIT_FAILURE);
			}
			value = atoi(arg);
			push(&stack, line_number, value);
		} else if (strcmp(opcode, "pall") == 0)
			pall(&stack, line_number);
		else if (strcmp(opcode, "pint") == 0)
			pint(&stack, line_number);
		else if (strcmp(opcode, "pop") == 0)
			pop(&stack, line_number);
	} fclose(file);
	return (EXIT_SUCCESS);
}
