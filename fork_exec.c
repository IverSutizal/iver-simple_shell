#include "main.h"
/**
 * _fork - forks the process.
 * @buffer: command line.
 * @token: command.
 * Return: an integer
**/
int _fork(char **token, char *buffer)
{
	pid_t pid = 0;
	int status = 0;
	char  wpid;
	(void)wpid;
	pid = fork();
	if (pid == 0)
	{
		if (execute(buffer, token[0], token[1]) == -1)
		{
			errors(token[0], token[1]);
			 free(buffer), free(token);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		errors(token[0], token[1]);
		return (0);
	}

	else
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	return (1);
}

/**
 * execute_command - exe.
 * @argument: error of the command.
 * @args: aguments of the command.
 * @line: line of command.
 * Return: an integer.
**/
int execute_command(char **args, char *line, char *argument)
{
	pid_t pid, wpid;
	int status;
	char us[128] = "/bin", *aux = "/b";
	(void)wpid;


	if (line[0] == aux[0] && line[1] == aux[1])
	{
		strcpy(us, line);
	}
	else
	{
		strcat(us, "/");
		strcat(us, line);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(us, args, NULL) == -1)
		{
			errors(args[0], argument);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		errors(args[0], argument);
		return (0);
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

