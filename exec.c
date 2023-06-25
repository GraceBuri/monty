#include "monty.h"

/**
* execute - function that runs the opcode
* @stack: pointer to the stack
* @tokens: split arguments of the line
* @line_number: bytecode is executed
*/
void execute(char **tokens, stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"sub", sub},
	{"mul", mul},
	{"div", divs},
	{"mod", mod},
	{"nop", nop},
	{NULL, NULL}

};
	int i = 0;

	if (input.num_tok == 2)
		input.arg = tokens[1];
	if (tokens && tokens[0][0] == '#')
		return;
	if (tokens[0] == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, tokens[0]);
		exit(EXIT_FAILURE);
	}
	while (ops[i].opcode != NULL)
	{
		if (strcmp(tokens[0], ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, tokens[0]);
	exit(EXIT_FAILURE);
}
