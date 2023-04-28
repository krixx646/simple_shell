#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 1024
#define USER_PROMPT "$$ "

extern char **environ;

/**
 * struct onions - linked list.
 * @node: cont.
 * @next: pointer.
 *
 * Description: linked list.
 */
typedef struct onions
{
	char *node;
	struct onions *next;
} onions;

/**
 * struct cookies - linked list.
 * @node: const.
 * @los: pointer.
 *
 * Description: linked list.
 */
typedef struct execmd_s
{
	char *alp;
	int (*los)(void);
} execmd_s;

/* String function */
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strchr(char *str, char ch);
int _strcmp(char *str2, char *str1, unsigned int count);


/* prompt function prototype */
void user_prompt(int stream, struct stat buffer);

/* print function prototype */
int _putchar(char c);

/* function prototype */
char **parse_line(char *string);

/* function free */
void free_up(char **tok, char *user_line, char *pat_vn, char *al_pat, int arg);
int execute_cmd(char **lim);
int num_cmd(execmd_s cookies[]);
int shell_env(void);
int exit_shell(void);

char *my_getenv_func(const char *tag);
char *my_getline_func(FILE *ops);

char **my_env_copyy(char **pop_py, unsigned int pop_pt);
int _strncmp(char *str1, char *str2, unsigned int count);
#endif
