#include "monty.h"

/**
 * find_op - checks for a command "opcode" and executes
 * @token: toke containing opcode to execute
 * @stack: list representation of stack
 * @line_number: number where opcode was found
 * Return: Success/Failure
 */

int find_op(char **token, stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;

	instruction_t op[] = {
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"null", NULL}
	};

	for (i = 0; i < 14; i++)
	{
		if (strcmp(op[i].opcode, token[0]) == 0)
		{
			op[i].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	frees(stack);
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, token[0]);
	return (EXIT_FAILURE);
}

/**
  * m_push - pushes an element to stack
  * @stack: pointer to the stack
  * @token: pointer to op
  * @line_number: number of line
  * Return: Success
  */
int m_push(stack_t **stack, char **token, unsigned int line_number)
{
	stack_t *new;
	int i = 0;

	if (token[1] == NULL)
		return (ferrors(0, line_number));
	while (token[1][i])
	{
		if (token[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (token[1][i] < '0' || token[1][i] > '9')
		{
			frees(stack);
			return (ferrors(0, line_number));
		}
		i++;
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (uerror(0));

	new->n = atoi(token[1]);
	if ((*stack) != NULL)
		(*stack)->prev = new;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
	return (EXIT_SUCCESS);
}

/**
 * m_qpush - pushes element to queue
 * @stack: pointer to stack
 * @token: pointer to op
 * @line_number: number of line
 * Return: Success
 */
int m_qpush(stack_t **stack, char **token, unsigned int line_number)
{
	stack_t *new, *tmp = NULL;
	int i = 0;

	if (token[1] == NULL)
		return (ferrors(0, line_number));
	while (token[1][i])
	{
		if (token[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (token[1][i] < '0' || token[1][i] > '9')
		{
			frees(stack);
			return (ferrors(0, line_number));
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (uerror(0));
	new->next = NULL;
	new->prev = NULL;
	new->n = atoi(token[1]);
	if (!stack || !(*stack))
	{
		(*stack) = new;
		return (EXIT_SUCCESS);
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/**
 * m_pall - prints the values of stack_t
 * @stack: pointer to the top of stack
 * @line_number: number of the line
 * Return: nada
 */
void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
