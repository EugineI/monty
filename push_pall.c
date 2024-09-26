#include "monty.h"
/**
 * push - adds an element to the stack
 * @stack: double pointer to stack
 * @line_number: line_number
 * @value: value
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *new_node;

	(void)line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 * pall - prints all arguments in the stack
 * @stack: double pointer to stack
 * @line_number: line number
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;

	(void)line_number;
	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

/**
 * is_integer - function to check if is integer
 * @str: string
 * Return: ruturns zero or one
 */

int is_integer(char *str)
{
	if (*str == '\0' || str == NULL)
	{
		return (0);
	}
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/**
 * free_stack - function to free stack
 * @stack: pointer to stack
 * Return: nothing
 */

void free_stack(stack_t *stack)
{
	stack_t *new;

	while (stack != NULL)
	{
		new = stack;
		stack = stack->next;
		free(new);
	}
}
