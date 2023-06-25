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
/**
 * rotl - rotates the stack to the top
 * @head: stacks first element
 * @line_number: line byte code is running
*/
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *tmp, *node;
	(void) line_number;

	if (*head == NULL || (*head)->next == NULL)
		return;

	node = (*head)->next;
	node->prev = NULL;
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = node;
}
/**
 * rotr - rotates the stack
 * @head: stack head
 * @line_number: bytecode line being run
*/
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	if (*head == NULL || (*head)->next == NULL)
		return;
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*head)->prev = tmp;
	(*head) = tmp;
}
