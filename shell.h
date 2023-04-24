#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>

/* Macros unit Variables*/

#include MAX_NUM 20;
#include UNUD_A 10;

/* String header files */

void print_prompt(char *prompt);
char *read_input();
int parse_input(char *input, char **argv);
char *find_command(char *command);
void execute_command(char *command, char **argv, char **environ);

char *strchr(const char *str, int c);
size_t strlen(const char *str);
char *getenv(const char *name);

/* Function Headers will be inserted here */

#endif
