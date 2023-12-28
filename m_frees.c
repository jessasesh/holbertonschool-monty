#include "monty.h"

/**
 * frees - frees memory allocated for stack
 * @stack: pointer to list rep of stack
 * Return: nada
 */

void frees(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
