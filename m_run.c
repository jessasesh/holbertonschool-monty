#include "monty.h"

/**
 * m_run - runs Monty
 * @fd: descriptor for file
 * Return: Success
 */
int m_run(FILE *fd)
{
	stack_t *stack = NULL;
	char *line = NULL, **token = NULL, delim[] = " \n\t\a\b";
	size_t len = 0, mode = 1;
	unsigned int line_number = 0, exit_status = EXIT_SUCCESS;

	while (getline(&line, &len, fd) != -1)
	{
		line_number++;
		if (empline(line, delim))
			continue;
		token = tokenizer(line, delim);
		if (token[0][0] == '#' || strcmp(token[0], "nop") == 0)
		{
			free(token);
			continue;
		}
		else if (strcmp(token[0], "stack") == 0)
			mode = 1;
		else if (strcmp(token[0], "queue") == 0)
			mode = 0;
		else if (strcmp(token[0], "push") == 0 && mode == 0)
			exit_status = m_qpush(&stack, token, line_number);
		else if (strcmp(token[0], "push") == 0 && mode == 1)
			exit_status = m_push(&stack, token, line_number);
		else
			exit_status = find_op(token, &stack, line_number);
		free(token);
		if (exit_status == EXIT_FAILURE)
			break;
	}
	frees(&stack);
	free(line);
	return (exit_status);
}

/**
 * tokenizer - splits the line
 * @line: pointer to line
 * @delim: delimiters " \n\t\a\b"
 * Return: pointer to token
 */
char **tokenizer(char *line, char *delim)
{
	char *tokens = NULL, **token = NULL;
	size_t bufsize = 0, i = 0;

	if (line == NULL || !*line)
		return (NULL);

	token = malloc(bufsize * sizeof(char *));
	if (token == NULL)
	{
		free(line);
		free(token);
		exit(uerror(0));
	}
	tokens = strtok(line, delim);
	while (tokens != NULL)
	{
		token[i] = strdup(tokens);
		if (token[i] == NULL)
		{
			free(line);
			free(token);
			exit(uerror(0));
		}
		i++;

		if (i >= bufsize)
		{
			bufsize *= 2;
			token = realloc(token, bufsize * sizeof(char *));
			if (token == NULL)
			{
				free(line);
				free(token);
				exit(uerror(0));
			}
		}
		tokens = strtok(NULL, delim);
	}
	token[i] = NULL;
	return (token);
}

/**
 * empline - checks if line only has delims
 * @line: pointer to line
 * @delims: string with delim characters
 * Return: 1 for delims
 */
int empline(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}
