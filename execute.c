#include "simple_shell.h"

/**
 * main - Entry point for the shell.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *prompt;
	char *buffer;
	size_t size;
	ssize_t control;
	char **command_args;

	argc = argc;
	prompt = "#cisfun$ ";
	size = 0;
	buffer = NULL;

	display_prompt(prompt);
	control = 0;
	while ((control = getline(&buffer, &size, stdin)) != -1)
	{
		if (control <= 1)
		{
			display_prompt(prompt);
			continue;
		}
		buffer[control - 1] = '\0';
		command_args = split_string(buffer, " ");

		execute_command(command_args[0], command_args, environ, argv[0]);

		free_str_array(command_args);
		display_prompt(prompt);
	}

	free(buffer);

	return (0);
}

/**
 * execute_command - executes a command provided by user
 * @pathname: The full path to the executable command
 * @argv: An array of arguments
 * @envp: An array of environmental variables (environ)
 * @program_name: For error message
 *
 * Return: Always sucess
 */
int execute_command(const char *pathname, char *const argv[],
		char *const envp[], char *program_name)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(pathname, argv, envp) == -1)
		{
			perror(program_name);
			_exit(1);
		}

		return (1);
	}
	else
		wait(&status);

	return (0);
}

/**
 * display_prompt - displays the prompt for the user to enter commands
 * @prompt: the prompt to be displayed
 *
 * Return: void
 */
void display_prompt(char *prompt)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
	}
}

/**
 * split_string - Splits a string and returns an array of the split string
 * @str: The string to be split
 * @delimeter: The delimeter to be used to split the string
 *
 * Return: An array of the split string
 */
char **split_string(char *str, char *delimeter)
{
	list_t *string_list;
	char **string_array;
	char *control;
	int i, size;

	string_list = NULL;
	control = strtok(str, delimeter);

	while (control != NULL)
	{
		add_element(&string_list, control);
		control = strtok(NULL, delimeter);
	}

	size = get_size(string_list);

	string_array = malloc(sizeof(char *) * (size + 1));
	if (string_array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		string_array[i] = _strdup(get_node(string_list, i)->str);
	}
	string_array[size] = NULL;

	free_list(string_list);
	return (string_array);
}

/**
 * free_str_array - frees an array of strings
 * @arr: the array
 *
 * Return: 0
 */
int free_str_array(char **arr)
{
	int i;

	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);

	return (0);
}
