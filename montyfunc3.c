#include "monty.h"
/**
 * divs - a function that divides the first two stack members
 * @head: pointer to the head of the stack
 * @line_number: line in which bytecode is being executed
*/
void divs(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	(*head)->next->n /= (*head)->n;
	pop(head, 0);
}
/**
 * mul - a function that multiplies the first two stack members
 * @head: pointer to the head of the stack
 * @line_number: line in which bytecode is being executed
*/

void mul(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	(*head)->next->n *= (*head)->n;
	pop(head, 0);
}
/**
 * mod - a function that gets the modulo of the first two stack members
 * @head: pointer to the head of the stack
 * @line_number: line in which bytecode is being executed
*/
void mod(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	(*head)->next->n %= (*head)->n;
	pop(head, 0);
}
