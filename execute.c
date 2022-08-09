#include "main.h"
/**
 * execute - find in command special caracter and run
 * @line2: command
 * @token: command.
 * @argument: error of the command.
 * Return: 0
 */
int execute(char line2[], char *token, char *argument)
{
	int lengthline2 = strlen(line2);
	int flaqsc = 0, ex = 0;
	char *copy = NULL;
	char *path;
	char **dpath;

	copy = calloc(lengthline2 + 1, sizeof(char));
	path = gpath();
	dpath = splitPath(path);
	flaqsc = flaqs(line2);
	strcpy(copy, line2);
	if (flaqsc == 0)
	{
		ex = run(line2, dpath, token, argument);
	}
	else if (flaqsc == 1)
	{
		ex = semi_colon(copy, dpath, token, argument);
	}
	else if (flaqsc == 3)
	{
		ex = pipe_separator(copy, dpath, token, argument);
	}
	free(path);
	free(copy);
	free(dpath);
	return (ex);
}
/**
 * count - count number of delimiter in the command
 * @line2: command
 * @c: delimiter
 * Return: number of the delimiter
 */
int count(char line2[], char c)
{
	int j = 0, k = 0;

	while (line2[j])
	{
		if (line2[j] == c)
			k++;
		j++;
	}
	return (k);
}
