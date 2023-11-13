#include "simple_shell.h"

/**
 * _getenv - gets the value of an environmental variable
 * @var: the variable
 *
 * Return: The value of an environmental variable, null if not found
 */
char *_getenv(char *var)
{
	int i;
	char *env_var;
	char *value;
	char *env_copy;
	char *duplicated_value;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_copy = strdup(environ[i]);
		if (env_copy == NULL)
			return (NULL);
		
		env_var = strtok(env_copy, "=");

		if (env_var != NULL && _strcmp(env_var, var) == 0)
		{
			value = strtok(NULL, "=");
			duplicated_value = strdup(value);
			free(env_copy);
			return duplicated_value;
		}

		free(env_copy);
	}

	return (NULL);

}

/**
 * getenvdirs - puts the value of an env into a list of dirs
 * @var: the env variables
 *
 * Return: The list of variables
 */
list_t *getenvdirs(char *var)
{
	char *env_value;
	list_t *dir_list;
	char *temp;

	dir_list = NULL;
	env_value = _getenv(var);

	if (env_value == NULL)
		return (NULL);

	temp = strtok(env_value, ":");

	while (temp != NULL)
	{
		add_element(&dir_list, temp);
		temp = strtok(NULL, ":");
	}

	free(env_value);
	return (dir_list);
}
