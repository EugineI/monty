#include "monty.h"

/**
 * pop - print element at the top of the stack
 * @stack: the double pointer
 * @line_number: line_number
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(new);
}
