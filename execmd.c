#include "shell.h"

void print_prompt(char *prompt)
{
	write(STDOUT_FILENO, prompt, _strlen(prompt));
}

char *read_input()
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read_len;

	read_len = getline(&input, &len, stdin);
	if (read_len == -1)
	{
		write(STDOUT_FILENO, "Terminating shell...\n", 20);
		exit(-1);
	}
	input[read_len - 1] = '\0';
	return input;
}

int parse_input(char *input, char **argv)
{
	int argc = 0;
	char *token, *new_line = " \t\n";
	
	token = strtok(input, new_line);
	
	while (token != NULL && argc < MAX_ARGV)
	{
		argv[argc] = token;
		argc++;
		token = strtok(NULL, new_line);
	}
	argv[argc] = NULL;
	
	if (argc == 0)
	{
		perror("unable to tokenize user input.\n");
		exit(-1);
	}
	return argc;
}


char *find_command(char *command)
{
	char *path, *path_copy, *dir, *cmd_path, *full_path;

	if (access(command, X_OK) == 0)
	{
		return strdup(command);
	}

	path = getenv("PATH");
	path_copy = _strdup(path);
	dir = strtok(path_copy, ":");
	cmd_path = NULL;
	
	while (dir != NULL && cmd_path == NULL)
	{
		full_path = malloc(_strlen(dir) + _strlen(command) + 2);
		
		if (full_path == NULL)
		{
			write(STDOUT_FILENO, "Error: failed to allocate memory.\n", 35);
			exit(-1);
		}
		sprintf(full_path, "%s/%s", dir, command);
		
		if (access(full_path, X_OK) == 0)
		{
			cmd_path = _strdup(full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	
	if (cmd_path == NULL)
	{
		full_path = malloc(_strlen("/bin/") + _strlen(command) + 2);
		if (full_path == NULL)
		{
			write(STDOUT_FILENO, "Error: failed to allocate memory.\n", 35);
			exit(-1);
		}
		sprintf(full_path, "/bin/%s", command);
		if (access(full_path, X_OK) == 0)
		{
			cmd_path = _strdup(full_path);
		}
		free(full_path);
	}
	free(path_copy);

	return (cmd_path);
}

void execute_command(char *command, char **argv)
{
	char *cmd_path;
	int status, w;
	pid_t pid;

	cmd_path = find_command(command);
	if (cmd_path == NULL)
	{
		printf("Command not found: %s\n", command);
		return;
	}
	pid = fork();
	
	if (pid == -1)
	{
		perror("fork() failed");
		exit(-1);
	}
	else if (pid == 0)
	{
		if (execve(cmd_path, argv, environ) == -1)
		{
			perror("execve() failed");
			exit(-1);
		}
	}
	else
	{
		do
		{
			w = waitpid(pid, &status, WUNTRACED | WCONTINUED);
			if (w == -1)
			{
				perror("waitpid() failed");
				exit(-1);
			}
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(cmd_path);
}
