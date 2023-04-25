#include "shell.h"

/**
 * _print_env - print the current environment variables.
 * @env: the array of environment variables.
 */
void _print_env(char **env)
{
        int i = 0;

        while (env[i] != NULL)
        {
                _putstr(env[i]);
                _putchar('\n');
                i++;
        }
}

/**
 * env_builtin - execute the env built-in command.
 * @env: the array of environment variables.
 *
 * Return: Always returns 0.
 */
int env_builtin(char **env)
{
        _print_env(env);
        return (0);
}

