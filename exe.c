#include "shell.h"

/**
 * builtin_handler - Handle builtin.
 * @edict: cmd.
 * @status: last cmd status.
 *
 * Return: 0 or -1 if fail.
 */
int builtin_handler(char **edict, int status)
{
	builtin_last[] = {
		{"env" print_env},
		{"cd", changes_dir},
		{"help", shows_help},
		{"echo", echo_words},
		{"record", show_record},
		{NULL, NULL}
	};
}
