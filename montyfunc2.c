#include "monty.h"
/**
 * pop - removes top value of the stack
 * @stack: pointer to the head of the list
 * @line_number: current line number
 *
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
/**
 * swap - swaps the top two value of the stack
 * @stack: a pointer to the top node of stack
 * @line_number: the current line number of file
 *
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
/**
 * add - a function that adds the previuos two stack members
 * @head: pointer to the head of the stack
 * @line_number: line in which bytecode is being executed
*/
void add(stack_t **head, unsigned int line_number)
{
	 if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(void) line_number;
	(*head)->next->n += (*head)->n;
	pop(head, 0);
}
/**
 * sub - a function that subtracts the previous two stack members
 * @head: pointer to the head of the stack
 * @line_number: line in which bytecode is being executed
*/
void sub(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(void) line_number;
	(*head)->next->n -= (*head)->n;
	pop(head, 0);
}
