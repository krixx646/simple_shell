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
	char *user_line, *pat_vn, *al_pat, **toks;
	struct stat buffer;
	int cmd_sta, pp_st;
	(void)arv;

	while (1 == 1)
	{
		user_prompt(STDIN_FILENO, buffer);
		user_line = my_getline_func(stdin);
		if (_strcmp(user_line, "\n", 1) == 0)
		{
			free(user_line);
			continue;
		}
		toks = parse_line(user_line);
		if (toks[0] == NULL)
			continue;
		cmd_sta = execute_cmd(toks);
		if (cmd_sta == 0 || cmd_sta == -1)
		{
			free(toks);
			free(user_line);
		}
		if (cmd_sta == 0)
			continue;
		if (cmd_sta == -1)
			exit(EXIT_SUCCESS);
		arc = 0;
		pat_vn = my_getenv_func("PATH");
		al_pat = _execvp(toks[0], al_pat, pat_vn);
		if (al_pat == NULL)
			al_pat = toks[0];
		else
			arc = 1;
		pp_st = process_child(al_pat, toks);
		if (pp_st == -1)
			write(STDERR_FILENO, "Process failed\n", 15);
		free_up(toks, pat_vn, user_line, al_pat, arc);
	}
	return (0);
}
