#include "shell.h"

/**
 * free_up_all - frees all memory allocated.
 * @tok: tokens.
 * @user_line: user input.
 * @pat_vn: path.
 * @al_pat: path.
 * @arc: flag.
 */
void free_up_all(char **tok, char *user_line, char *pat_vn, char *al_pat, int arc)
{
	free(pat_vn);
	free(user_line);
	free(tok);
	if (arc == 1)
		free(al_pat);
}
