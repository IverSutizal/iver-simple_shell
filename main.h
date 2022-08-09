#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <limits.h>
#include <stdint.h>

extern char **environ;

void sighandler(int sig_int);
int _putchar(char c);
void _env(char **com);
char **split_command(char *line);
int execute_command(char **args, char *line, char *argument);
int _fork(char **token, char *buffer);
int execute(char line2[], char *token, char *argument);
void errors(char *token, char *argument);
char *gpath();
char **splitPath(char *path);
void split(char line2[], char *slicedCommand[], char c[]);
int flaqs(char line2[]);
void splitSpace(char *argv[], char line2[]);
int run(char line2[], char *dpath[], char *token, char *argument);
int semi_colon(char copy[], char *dpath[], char *token, char *argument);
int pipe_separator(char copy[], char *dpath[], char *token, char *argument);
char *checkPath(char **dpath, char *argv0);
int count(char line2[], char c);
char *unePath(char *dpath, char *argv0);
#endif
