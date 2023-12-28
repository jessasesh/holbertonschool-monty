#include "monty.h"

/**
 * uerror - prints usage error message
 * @f: ype of error
 * Return: EXIT_FAILURE
 */
int uerror(int f)
{
	char *errors[2] = {"Error: malloc failed", "USAGE: monty file"};

	fprintf(stderr, "%s\n", errors[f]);
	return (EXIT_FAILURE);
}

/**
 * oerror - prints file open error message
 * @filen: file that failed to open
 * Return: EXIT_FAILURE
 */
int oerror(char *filen)
{
	fprintf(stderr, "Error: Can't open file %s\n", filen);
	return (EXIT_FAILURE);
}

/**
 * ferrors - prints the errors
 * @f: index to find type of error
 * @line_number: line number in file with error
 * Return: EXIT_FAILURE
 */
int ferrors(int f, unsigned int line_number)
{
	char *errors[] = {"usage: push integer", "can\'t pint, stack empty",
	     "can\'t pop an empty stack", "can\'t swap, stack too short",
	     "can\'t add, stack too short"};

	fprintf(stderr, "L%d: %s\n", line_number, errors[f]);
	return (EXIT_FAILURE);
}
