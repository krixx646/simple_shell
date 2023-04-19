#include "shell.h"

/**
 * main - start of function.
 * @argc: argument count.
 * @argv: array of string pointers containing command line arguments.
 *
 * Return: int.
 */
int main(int argc, char **argv)
{
	char *prompt = "simple_shell$ ";
	char *markptr = NULL, *markptr_dup = NULL;
	size_t size = 0;
	ssize_t str;
	const char *dim = " \n";
	int count, tok_count = 0;
	char *tok;

	if (argc > 1)
	{
		prompt = argv[1];
	}

	while (1)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		str = getline(&markptr, &size, stdin);
		if (str == -1)
		{
			write(STDOUT_FILENO, "Exiting shell....\n", strlen("Exiting shell....\n"));
			return (-1);
		}

		markptr_dup = malloc(sizeof(char) * str);
		if (markptr == NULL)
		{
			perror("tsh: memory not allocated");
			return (-1);
		}
		strcpy(markptr_dup, markptr);
		tok = strtok(markptr, dim);

		while (tok != NULL)
		{
			tok_count++;
			tok = strtok(NULL, dim);
		}

		argv = malloc(sizeof(char *) * (tok_count + 1));
		tok = strtok(markptr_dup, dim);

		for (count = 0; tok != NULL; count++)
		{
			argv[count] = malloc(sizeof(char) * strlen(tok));
			strcpy(argv[count], tok);
			tok = strtok(NULL, dim);
		}
		argv[count] = NULL;

		execute_command(argv, argc);

		for (count = 0; count < tok_count; count++)
		{
			free(argv[count]);
		}
		free(argv);
	}
	free(markptr);
	free(markptr_dup);
	return (0);
}
