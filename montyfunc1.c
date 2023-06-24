#include "monty.h"
/**
* push - push an element to the stack
* @stack: double pointer to the stack
* @line_number: line opcode is searched
* Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
	int n;
	char *arg = input.arg;

	if (!arg && is_numeric(arg))
	{
		fprintf(stderr, "L%u: usage push integer\n", line_number);
		return;
	}
	n = atoi(arg);
	addnode(stack, n);
}


/**
* pall - print all elements of the stack
* @stack: pointer to the head of the stack
* @line_number: line opcode is searched
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
* addnode - add a new node to top of the stack
* @stack: pointer to the stack
* @n: value to be added
*/
void addnode(stack_t **stack, int n)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (!newnode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = newnode;
		newnode->prev = NULL;
	}

	*stack = newnode;
}
/**
* free_stack - function to free doubly linked list
* @head: head of the stack
*/
void free_stack(stack_t **head)
{
	stack_t *temp;
	stack_t *current = *head;


	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*head = NULL;
}
/**
* pint - a function that prints top value of the stack
* @stack: a pointer to head of the doubly linked list
* @line_number: the current working line number of file
*/
void pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		return;
	}
	printf("%d\n", (*stack)->n);
}
