#include "monty.h"

void betty_no_more(void);

/**
 * main - entry point function for Monty
 * @ac: number of arguments
 * @av: pointer to array of arguments
 * Return: 0
 */
int main(int ac, char **av)
{
	FILE *fd = NULL;
	int exit_status = EXIT_SUCCESS;

	if (ac != 2)
		return (uerror(1));

	fd = fopen(av[1], "r");
	if (fd == NULL)
		return (oerror(av[1]));

	exit_status = m_run(fd);
	fclose(fd);
	return (exit_status);
		oerror(av[1]);
	m_run(fd);
	exit(EXIT_SUCCESS);
	return (0);
}
