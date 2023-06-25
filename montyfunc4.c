#include "monty.h"
/**
 * pchar - prints top character on stack
 * @head: head of the stack
 * @line_number: number byte code is being interpreted
 */
void pchar(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	tmp = *head;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (tmp->n > 127 || tmp->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}
/**
 * pstr - prints top string of the stack
 * @head: head of the stack
 * @line_number: line bytecode is being interpreted
*/
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	tmp = *head;
	while (tmp != NULL)
	{
		if (tmp->n > 127 || tmp->n <=  0)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
