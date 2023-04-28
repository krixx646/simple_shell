#include "shell.h"

/**
 * user_prompt - checks if the shell is running in an interactive mode.
 */
void prompt(int stream, struct stat buffer)
{
	int j;

	fstat(stream, &buffer);

	if(S_ISCHR(buffer.st_mode))
	{
		for (j = 0; PROMPT[j] != '\0'; j++)
		{
			_putchar(PROMPT[j]);
		}
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
