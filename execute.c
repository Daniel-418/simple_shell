#include "simple_shell.h"

/**
 * main - Entry point for the shell.
 *
 * Return: Always 0.
 */
int main()
{
	char *prompt;
	char *buffer;
	size_t size;
	ssize_t control;
	char *command_args[2];

	prompt = "#cisfun$ ";
	display_prompt(prompt);

	size = 0;
	buffer = NULL;

	while ((control = getline(&buffer, &size, stdin)) != -1)
	{
		buffer[control - 1] = '\0';
		command_args[0] = buffer;
		command_args = NULL;

		execute_command(command_args[0], command_args, environ, prompt);
		display_prompt(prompt);
	}

	free(buffer);

/** 
 * execute_command - executes a command provided by user
 * @pathname: The full path to the executable command
 * @argv: An array of arguments
 * @envp: An array of environmental variables (environ)
 * @prompt: The name of the program. (For errors)
 * 
 * Return: Always sucess
 */
int execute_command(const char *pathname, char *const argv[], 
		char *const envp[], char *prompt)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(pathname, argv, envp) == -1)
			perror(prompt);

		return (0);
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
