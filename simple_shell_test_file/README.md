Simple Shell in C


This is a project to build a simple shell in C that allows users to interact with the operating system via a command line interface. The shell is capable of executing basic commands, handling built-in commands, and implementing piping and input/output redirection.

Getting Started
To use the shell, simply compile the shell.c file using a C compiler such as gcc and then run the resulting executable file. Once the shell is running, you can enter commands in the same way as you would with a regular terminal.

Features
The shell includes the following features:

Basic command execution
Handling of built-in commands such as cd and exit
Piping of commands using the | symbol
Input redirection using the < symbol
Output redirection using the > symbol

Usage
To use the shell, simply enter commands at the prompt. For example:

$ ls

This will execute the ls command and display the list of files in the current directory.

To use a built-in command, simply enter the command name followed by any arguments. For example:

$ cd /path/to/directory

This will change the current working directory to the specified path.

To pipe commands, use the | symbol between the commands. For example:

$ ls | grep README

This will list all the files in the current directory and then filter for those containing the string "README".

To redirect input or output, use the < or > symbol followed by the file name. For example:

$ cat < file.txt > output.txt


This will read the contents of the file.txt file and write them to the output.txt file.

Contributions
Contributions to this project are welcome. If you find a bug or want to suggest an improvement, please create a new issue or submit a pull request with your changes.

License
This project is licensed under the MIT License. See the LICENSE file for details.

