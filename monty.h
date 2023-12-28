#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*opcodes*/

/*main.c*/
int main(int ac, char **av);

/*m_frees.c*/
void frees(stack_t **stack);

/*m_run.c*/
int m_run(FILE *fd);
char **tokenizer(char *line, char *delim);
int empline(char *line, char *delims);

/*m_exec.c*/
int find_op(char **token, stack_t **stack, unsigned int line_number);
int m_push(stack_t **stack, char **token, unsigned int line_number);
int m_qpush(stack_t **stack, char **token, unsigned int line_number);
void m_pall(stack_t **stack, unsigned int line_number);

/*m_actions.c*/
void m_pint(stack_t **stack, unsigned int line_num);
void m_pop(stack_t **stack, unsigned int line_num);
void m_swap(stack_t **stack, unsigned int line_num);
void m_add(stack_t **stack, unsigned int line_num);

/*error_mess.c */
int uerror(int f);
int oerror(char *filen);
int ferrors(int f, unsigned int line_number);

#endif
