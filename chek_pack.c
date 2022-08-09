#include "main.h"
/**
 * checkPath - check with stat in the folders PATH with command
 * @dpath: pointer array of dir in PATH
 * @argv0: pointer to cmd name
 * Return: pointer if found, NULL not found
 */
char *checkPath(char **dpath, char *argv0)
{
	struct stat mao;
	char *completline;
	int i = 0;

	while (dpath[i])
	{
		completline = unePath(dpath[i], argv0);
		if (stat(completline, &mao) == 0)
			return (completline);
		i++;
	}
	return (NULL);
}

/**
 * unePath - Concatenate command argv[0] to each directory path
 * @dpath: pointer a one dir PATH
 * @argv0: command
 * Return: pointer string dir + cmd or NULL error
 */
char *unePath(char *dpath, char *argv0)
{
	int dpathlen, argv0len, len, i = 0, j = 0;
	char *path_cmd;

	dpathlen = strlen(dpath);
	argv0len = strlen(argv0);
	len = dpathlen + argv0len;
	path_cmd = calloc(len + 2, sizeof(char));
	if (path_cmd == NULL)
	{
		write(1, "Error: malloc catpath\n", 22);
		return (NULL);
	}
	while (dpath[i])
	{
		path_cmd[i] = dpath[i];
		i++;
	}
	path_cmd[i] = '/';
	i++;
	while (argv0[j])
	{
		path_cmd[i] = argv0[j];
		j++;
		i++;
	}
	path_cmd[i] = '\0';
	return (path_cmd);
}

