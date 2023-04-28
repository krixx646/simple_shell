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
#define USER_PROMPT "$ "

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
 * struct execmd_s - linked list.
 * @node: const.
 * @los: pointer.
 *
 * Description: linked list.
 */
typedef struct execmd_s
{
	char *node;
	int (*los)(void);
} execmd_s;

/* String function */
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strchr(char *str, char ch);
int _strcmp(char *str2, char *str1, unsigned int count);


/* prompt function prototype */
void prompt(int stream, struct stat buffer);

/* print function prototype */
int _putchar(char c);

/* function prototype */
char **parse_line(char *string);

/* function free */
<<<<<<< HEAD
void free_up_all(char **tok, char *user_line, char *pat_vn, char i*al_pat, int arg);
=======
void free_up(char **tok, char *user_line, char *pat_vn, char *al_pat, int arg);
>>>>>>> 9e52dcddd198f9658d478c8c59c09a2ad32af55f

char *my_new_getline(FILE *ops);
#endif
