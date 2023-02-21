#include "main.h"

/**
 * main - main program for the simple shell
 * @void: This function takes no argument
 *
 * Return: 1 if successful, 0 if not
 */
int main(void)
{
	int flag = 0;
	char *usr_input = NULL;
	char **args; 
	size_t length = 0;
	int status;
	int count;

	while (flag == 0)
	{
		printf(PROMPT);
		getline(&usr_input, &length, stdin);

		args = tokenize_string(usr_input, " \n");

		execute_command(args[0], args, environ);

		for (count = 0; args[count] != NULL; count++)
			free(args[count]);
		free(args);

		wait(&status);
	}

	free(usr_input);
	return (0);
}

/**
 * execute_command - executes the command passed
 * @command: command to be executed
 * @args: The array of the arguments
 * @environ: The environmental variables
 *
 * Return: 0 if successful, 1 if not.
 */
int execute_command(char *command, char **args, char** environ)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (child_pid == 0)
	{
		execve(command, args, environ);
		perror("Error");
		return (1);
	}

	return (0);
}

/**
 * tokenize_string: tokenizes a string and store them in
 * a null terminated array.
 * @str: The string to be tokenized.
 * @delimeter: The delimeter to be used.
 *
 * Return: A string array containing the tokenized string.
 */
char **tokenize_string(char *str, char *delimeter)
{
	char **tokens = NULL;
	char *token;
	unsigned int count = 0;
	char *strcopy = strdup(str);

	token = strtok(strcopy, delimeter);

	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delimeter);
	}
	
	tokens = malloc((sizeof(char *) * count) + 1);
	
	strcopy = strdup(str);
	token = strtok(strcopy, delimeter);
	count = 0;
	while (token != NULL)
	{
		tokens[count] = malloc(sizeof(token));
		tokens[count] = strdup(token);
		count++;
		token = strtok(NULL, delimeter);
	}

	tokens[count] = NULL;

	return (tokens);
}
