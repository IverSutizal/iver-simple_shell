#include "main.h"
/**
 * _getline - funtion to plit
 * readc - read line command
 * Return: string line with line break
 */
char *_getline(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t len_string = 0;

	len_string = getline(&line, &bufsize, stdin);
	if (len_string == -1)
		exit(0);
	return (line);
}
/**
 * sighandler - keep shell when user press control + c
 * @signo: handler
 * Return: nothing
*/
void sighandler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\nWill-># ");
		fflush(stdout);
	}
}
/**
 * main - mini shell
 * @ac: number of arguments.
 * @av: arguments.
 * Return: Always 0.
 */

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *line = NULL;
	char *buffer = NULL;
	char **token = NULL;
	int cont = 0;
	int k = 0;

	signal(SIGINT, sighandler);
	while (1)
	{
		cont++;
		printf("Will-># ");
		line = _getline();

		if (!strcmp(line, "\n"))
			continue;

		buffer = calloc(strlen(line) + 1, sizeof(char));
		k = strlen(line) - 1;
		strncpy(buffer, line, k);
		token = split_command(line);
		if (!strcmp("env", token[0]))
		{
			_env(token);
			free(line), free(buffer), free(token);
			continue;
		}
		if (!strncmp(token[0], "exit", 4))
			return (0);

		if (line[0] != '/')
			_fork(token, buffer);

		else
			execute_command(token, line, token[1]);

		free(line), free(token), free(buffer);
	}
	return (0);
}


/**
 * _env - prints the enviroment varibles.
 * @com: commands
**/

void _env(char **com)
{
	int i;
	char *s = *environ;

	if (com[1] != NULL)
		return;
	for (i = 0; s; i++)
	{
		write(STDIN_FILENO, s, strlen(s));
		write(STDIN_FILENO, "\n", 1);
		s = *(environ + i);
	}
}
