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
#define PROMPT "$ "

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
void free_up_all(char **tok, char *user_line, char *pat_vn, char *al_pat, int arg);

#endif
