#include "shell.h"

/**
 * free_up - frees all memory allocated.
 * @tok: tokens.
 * @user_line: user input.
 * @pat_vn: path.
 * @al_pat: path.
 * @arc: flag.
 *
 * Return: no return.
 */
void free_up(char **tok, char *user_line, char *pat_vn, char *al_pat, int arc)
{
	free(pat_vn);
	free(user_line);
	free(tok);
	if (arc == 1)
		free(al_pat);
}

/**
 * _free - free.
 * @arv: char argument.
 * @arc: unsigned int argument.
 *
 * Retrun: no return.
 */
void _free(char **arv, unsigned int arc)
{
	unsigned int mee;

	for (mee = 0; mee < arc; mee++)
	{
		free(arv[mee]);
	}
	free(arv);
}
