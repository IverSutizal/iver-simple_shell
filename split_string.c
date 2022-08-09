#define T_B_SIZE 1024
#define T_CUT " \t\r\n\a"
#include "main.h"
/**
 * split_command - split a line into tokens.
 * @line: line to split.
 * Return: An array of tokens.
**/
char **split_command(char *line)
{
	int buffer = T_B_SIZE, i = 0;
	char **tokens = malloc(buffer);
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, T_CUT);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		if (i >= buffer)
		{
			buffer += T_B_SIZE;
			tokens = realloc(tokens, buffer);
			if (!tokens)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, T_CUT);
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * errors - prints the error with it's type.
 * @token: command.
 * @argument: error of the command.
**/
void errors(char *token, char *argument __attribute__((unused)))
{
	char  *message = "command not found";
	char *st = NULL;
	int i;

	st = calloc(200, sizeof(char));

	strcat(st, token);
	strcat(st, ": ");
	strcat(st, message);
	strcat(st, "\n");

	for (i = 0; st[i] != '\0'; i++)
		;
	write(STDERR_FILENO, st, i);
	free(st);
}
