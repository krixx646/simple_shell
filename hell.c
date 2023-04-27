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

	while (1 == 1)
	{
		write(STDIN_FILENO, buffer);
		user_line = getline(stdin);
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
			exit(Exit_SUCCESS);
		arc = 0;
		pat_vn = _getenv("PATH");
		al_path = _execvp(toks[0], al_pat, pat_vn);
		if (al_path == NULL)
			al_pat = toks[0];
		else
			arc = 1;
		pp_st = process_child(al_pat, toks);
		if (pp_st == -1)
			perror(2);
		free_up_all(pat_vn, toks, user_line, al_pat, arc);
	}
	return (0);
}
