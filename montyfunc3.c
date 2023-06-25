#include "monty.h"
/**
 * divs - a function that divides the first two stack members
 * @head: pointer to the head of the stack
 * @line_number: line in which bytecode is being executed
*/
void divs(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
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
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
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
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(void) line_number;
	(*head)->next->n %= (*head)->n;
	pop(head, 0);
}
/**
* is_numeric - Checks if a string is a number
* @str: String parameter
* Return: int
*/
int is_numeric(const char *str)
{
	int digit_count = 0;

	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '+' || *str == '-')
		str++;

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);

		digit_count++;
		str++;
	}

	return (digit_count > 0);
}
