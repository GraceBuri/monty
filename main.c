#include "monty.h"
/**
 * main - my monty code intepreter
 * @argc: number of arguments from user
 * @argv: monty file
 * Return: 0 a success
 */
user_input input = {0, NULL, 0};

int main(int argc, char *argv[])
{
	char *lineptr = NULL;
	char **tokens;
	FILE *file;
	size_t size = 0;
	ssize_t content = 1;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		printf(stderr, "Error: Can't open file %s\n", argv[1])
		exit(EXIT_FAILURE);
	}
	while ((content = getline(&lineptr, &size, file)) != -1)
	{
		tokens = tokenize(lineptr);
		execute(tokens, &stack, line_number);
		free(tokens);
		line_number++;
		input.num_tok = 0;
		input.arg = NULL;
	}
	input.arg = NULL;
	free(lineptr);
	free_stack(&stack);
	fclose(file);
	return (0);
}
