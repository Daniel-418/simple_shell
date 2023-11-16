#include "simple_shell.h"

/**
 * shell_loop - entry point for shell
 * @program_name: Name of the program for errors
 * @prompt: the prompt for the shell
 *
 * Return: void
 */
void shell_loop(char *program_name, char *prompt)
{
	char *buffer;
	size_t size;
	ssize_t control;
	char **command_args;
	char *command;

	size = 0;
	buffer = NULL;

	display_prompt(prompt);
	control = 0;

	while ((control = _getline(&buffer, &size, STDIN_FILENO)) != -1)
	{
		if (control <= 1)
		{
			display_prompt(prompt);
			continue;
		}
		buffer[control - 1] = '\0';
		command_args = split_string(buffer, " ");
		command = get_command_path(command_args[0]);

		execute_command(command, command_args, environ, program_name);
		free(command);

		free_str_array(command_args);
		display_prompt(prompt);
	}

	free(buffer);
}

/**
 * get_command_path - gets the full path of a command
 * @command: the command
 *
 * Return: The full path to the command, null if the command cannot be found
 */
char *get_command_path(char *command)
{
	list_t *path_dirs;
	char *fullpath, *fullpathslash;
	struct stat st;
	int i;

	if (stat(command, &st) == 0)
		return (_strdup(command));

	path_dirs = getenvdirs("PATH");

	for (i = 0; i < get_size(path_dirs); i++)
	{
		fullpathslash = _strcat(get_node(path_dirs, i)->str, "/");
		fullpath = _strcat(fullpathslash, command);
		free(fullpathslash);

		if (stat(fullpath, &st) == 0)
		{
			free_list(path_dirs);
			return (fullpath);
		}

		free(fullpath);
	}

	free_list(path_dirs);
	return (NULL);
}
