#include "monty.h"
/**
 * tokenize - a function that tokenizes each line of user
 * @str: pointer to the users input
 * Return: tokens for the line
*/


char **tokenize(char *str)
{
	char *token;
	char **tokens;
	int i = 0;

	tokens = malloc(sizeof(char *) * 3);
	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	token = strtok(str, " \n\t\r");
	while (token != NULL && i < 2)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n\t\r");
		i++;
	}

	tokens[i] = NULL;
	input.num_tok = i;
	input.arg = NULL;
	return (tokens);
}
