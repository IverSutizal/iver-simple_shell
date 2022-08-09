#include "main.h"
/**
 * gpath - Gets the PATH environment.
 * Return: Pointer value of PATH.
 */
char *gpath()
{
	unsigned int i = 0, j = 5, k = 0;
	char *s, **e = environ;

	while (e[i])
	{
		if (e[i][0] == 80 && e[i][3] == 72 && e[i][4] == 61)
		{
			s = calloc(PATH_MAX, sizeof(char));
			if (s == NULL)
			{
				write(1, "Error: failed malloc gpath\n", 27);
				return (NULL);
			}
			while (e[i][j])
			{
				s[k] = e[i][j];
				k++;
				j++;
			}
			s[k] = '\0';
			return (s);
		}
		i++;
	}
	return (0);
}
/**
 * splitPath - Splits PATH each ':'
 * @path: Pointer value PATH
 * Return: Pointer each directories
 */
char **splitPath(char *path)
{
	char **d;
	char *carp;
	int i = 0;

	d = calloc(PATH_MAX, sizeof(char));
	if (d == NULL)
	{
		write(1, "Error: failed malloc splitPath\n", 31);
		return (NULL);
	}
	carp = strtok(path, ":");
	while (carp)
	{
		d[i] = carp;
		carp = strtok(NULL, ":");
		i++;
	}
	d[i] = NULL;
	return (d);
}

/**
 * flaqs - search delimiters in the command
 * @line2: command
 * Return: 1 is found, else 0
 */
int flaqs(char line2[])
{
	if (strchr(line2, ';') != NULL)
		return (1);
	else if (strchr(line2, '#') != NULL)
		return (2);
	else if (strchr(line2, '|') != NULL)
		return (3);
	else if (strchr(line2, '&') != NULL)
		return (4);
	else if (strchr(line2, '$') != NULL)
		return (5);
	return (0);
}

/**
 * splitSpace - cut each space
 * @argv: array save cut
 * @line2: name of filecommand complete
 * Return: 0
 */
void splitSpace(char *argv[], char line2[])
{
	char *puntero;
	int i = 0;

	puntero = strtok(line2, " ");
	while (puntero)
	{
		argv[i] = puntero;
		puntero = strtok(NULL, " ");
		i++;
	}
	argv[i] = NULL;
}

