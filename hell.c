#include "shell.h"
/**
 * main - start of function.
 * @arv: array of string.
 * @arc: numbers of array.
 *
 * Return: 0 Always(Success)
 */
int main(int arc, char **arv)
{
	int count = 0, grade = 1, star = 0;
	char *data, **edict;
	(void)arc;

	if (arv[1] != NULL)
		read_input(arv[1], arv);
	signal(SIGINT, signal_to_handle);

	while (true)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prompt();
		data = _getline();
		if (data[0] == '\0')
		{
			continue++;
		}
		record(data);
		edict = parse_line(data);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_shell(edict. data, arv, count);
		}
		else if (review_builtin(edict, star))
		{
			star = examine_builtin(edict, star);
			free_up(edict, data);
			continue;
		}
		else
		{
			star = look_cmd(edict, dat, count, arv)
		}
		free_up(edict, data);
	}
	return (grade);
}
