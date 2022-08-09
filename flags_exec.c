#include "main.h"
/**
 * run - execute command
 * @line2: command
 * @dpath:directories the path
 * @token: command.
 * @argument: error of the command.
 * Return: 0
 */
int run(char line2[], char *dpath[], char *token, char *argument)
{
	int x = 0, ex = 0;
	char *dpathcmd;
	char **argv = NULL;

	x = (count(line2, ' ')) + 2;
	argv = calloc(x, sizeof(char *));
	splitSpace(argv, line2);
	dpathcmd = checkPath(dpath, argv[0]);
	if (dpathcmd == NULL)
	{
		free(dpathcmd);
		errors(token, argument);
	}
	else
		ex = execve(dpathcmd, argv, environ);
	free(argv);
	return (ex);
}
/**
 * semi_colon - execute two command
 * @copy: comand complete
 * @dpath: directory path
 * @token: command.
 * @argument: error of the command.
 * Return: 0
 */
int semi_colon(char copy[], char *dpath[], char *token, char *argument)
{
	int x = 0, a = 0, b = 0, ex = 0, status = 0;
	char *dpathcmd, *ex1, *ex2;
	char *ppp[2], **argv1 = NULL, **argv2 = NULL;
	pid_t pid2, wpid;
	(void)wpid;

	split(copy, ppp, ";"), a = strlen(ppp[0]), b = strlen(ppp[1]);
	ex1 = calloc(a, sizeof(char *)), ex2 = calloc(b, sizeof(char *));
	strcpy(ex1, ppp[0]), strcpy(ex2, ppp[1]);
	x = (count(ex1, ' ')) + 2, argv1 = calloc(x, sizeof(char *));
	splitSpace(argv1, ex1), dpathcmd = checkPath(dpath, argv1[0]);
	if (dpathcmd == NULL)
		errors(token, argument);
	else
	pid2 = fork();
	if (!pid2)
	{
		if (execve(dpathcmd, argv1, environ) == -1)
		{ errors(token, argument);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid2 < 0)
	{ errors(token, argument);
		return (0);
	}
	else
	{
		do {wpid = waitpid(pid2, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	x = (count(ex2, ' ')) + 2;
	argv2 = calloc(x, sizeof(char *));
	splitSpace(argv2, ex2), dpathcmd = checkPath(dpath, argv2[0]);
	if (dpathcmd == NULL)
		errors(token, argument);
	else
		ex = execve(dpathcmd, argv2, environ);
	return (ex);
}
/**
 * pipe_separator - execute two command
 * @copy: comand complete
 * @dpath: directory path
 * @token: command.
 * @argument: error of the command.
 * Return: 0
 */
int pipe_separator(char copy[], char *dpath[], char *token, char *argument)
{
	int x = 0, a = 0, b = 0, ex = 0, status = 0;
	char *dpathcmd = NULL, *ex1, *ex2;
	char *ppp[2], **argv1 = NULL, **argv2 = NULL;
	pid_t pid2, wpid;
	(void)wpid;

	split(copy, ppp, "|");
	a = strlen(ppp[0]), b = strlen(ppp[1]);
	ex1 = calloc(a, sizeof(char)), ex2 = calloc(b, sizeof(char));
	strcpy(ex1, ppp[0]), strcpy(ex2, ppp[1]);
	x = (count(ex1, ' ')) + 2, argv1 = calloc(x, sizeof(char *));
	splitSpace(argv1, ex1), dpathcmd = checkPath(dpath, argv1[0]);
	if (dpathcmd == NULL)
		errors(token, argument);
	else
	pid2 = fork();
	if (!pid2)
	{
		if (execve(dpathcmd, argv1, environ) == -1)
		{ errors(token, argument);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid2 < 0)
	{ errors(token, argument);
		return (0);
	}
	else
	{
		do {wpid = waitpid(pid2, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	x = (count(ex2, ' ')) + 2, argv2 = calloc(x, sizeof(char *));
	splitSpace(argv2, ex2), dpathcmd = checkPath(dpath, argv2[0]);
	if (dpathcmd == NULL)
		errors(token, argument);
	else
		ex = execve(dpathcmd, argv2, environ);
	return (ex);
}

/**
 * split - cut each delimiter
 * @line2: command
 * @slicedCommand: array save cut
 * @c: delimiter
 * Return: 0
 */
void split(char line2[], char *slicedCommand[], char c[])
{
	char *puntero;
	int i = 0;

	puntero = strtok(line2, c);
	while (puntero)
	{
		slicedCommand[i] = puntero;
		puntero = strtok(NULL, c);
		i++;
	}
}
