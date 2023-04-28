#include "shell.h"

/**
 * user_prompt - checks if the shell is running in an interactive mode.
 *
 * Return: no return.
 */
void user_prompt(void)
{
	PROMPT("$ ");
}

/**
 * show_err - print error.
 * @data: user input.
 * @count: lenght.
 * @arv: char variable.
 *
 * Return: no return.
 */
void show_err(char *data, int count, char **arv)
{
	char *is;

	PROMPT(arv[0]);
	PROMPT(": ");
	is = _itoa(count);
	PROMPT(is);
	free(is);
	PROMPT(": ");
	PROMPT(data);
	PROMPT(": not found\n");
}
