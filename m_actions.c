#include "monty.h"

/**
 * m_pint - prints top value of stack
 * @stack: pointer to stack list
 * @line_num: working line number of file
 */
void m_pint(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		ferrors(1, line_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", temp->n);
}


/**
 * m_pop - removes top value in stack
 * @stack: pointer to stack_t list
 * @line_num: number of line of file
 */
void m_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		ferrors(2, line_num);
		exit(EXIT_FAILURE);
	}

	if (temp->next)
		temp->next->prev = temp->prev;
	*stack = temp->next;
	free(temp);
}

/**
 * m_swap - swaps two values at top of stack
 * @stack: pointer to top of list
 * @line_num: number of the line of a file
 */
void m_swap(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		ferrors(3, line_num);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = temp;
}

/**
 * m_add - adds the two top values of stack
 * @stack: pointer to stack list
 * @line_num: line number of file
 */
void m_add(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		ferrors(4, line_num);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = temp;
	m_pop(stack, line_num);
}
