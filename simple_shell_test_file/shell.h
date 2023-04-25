#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>
#include "shell.h"
#include <stddef.h>

extern char **environ;

#define BUFFER_SIZE 1024

#define MAX_ARGV 10

/* function header */
void _print_prompt(char *prompt);
void exit(int status);
char *_read_input();
int _parse_input(char *input, char **argv);
char *_find_command(char *command);
void _execute_command(char *command, char **argv);
int _strlen(char *str);
char *_strchr(char *str, char ch);
char *_strdup(char *string);
int _strcmp(char *str1, char *str2);
int env_builtin(char **env);


/* _print functions */
int _putchar(char c);
int _putstr(char *str);

#endif