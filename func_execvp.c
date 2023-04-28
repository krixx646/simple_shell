#include "shell.h"
/**
 * search_fullpath - searches for the full path.
 * @al_pat: path to command.
 * @pat_cmd: cmd to search.
 * @pat_vn: path.
 * Return: a pointer.
 */
char *search_fullpath(char *al_pat, char *pat_cmd, char *pat_vn)
{
	char *pat_pp, *toks;
	unsigned int count, pat_op, ops_pat;

	count = _strlen(pat_cmd);
	ops_pat = _strlen(pat_vn);
	pat_pp = malloc(sizeof(char) * ops_pat + 1);
	if (pat_pp == NULL)
	{
		perror("Error");
		return (NULL);
	}
	_strcpy(pat_pp, pat_vn);
	toks = strtok(pat_pp, ":");
	if (toks == NULL)
		toks = strtok(NULL, ":");
	while (toks != NULL)
	{
		pat_op = _strlen(toks);
		al_pat = malloc(sizeof(char) * (pat_op + count) + 2);
		if (al_pat == NULL)
		{
			perror("Error");
			return (NULL);
		}
		_strcpy(al_pat, toks);
		al_pat[pat_op] = '/';
		_strcpy(al_pat + pat_op + 1, pat_cmd);
		al_pat[pat_op + count + 1] = '\0';
		if (access(al_pat, X_OK) != 0)
		{
			free(al_pat);
			al_pat = NULL;
			toks = strtok(NULL, ":");
		}
		else
			break;
	}
	free(pat_pp);
	return (al_pat);
}
