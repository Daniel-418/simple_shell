#include "simple_shell.h"

/**
 * _strlen - counts the number of letters in a string
 * @str: The string
 *
 * Return: the numbers of letters in the string
 */
size_t _strlen(const char *str)
{
	size_t count;

	if (str == NULL)
		return (0);

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}

	return (count);
}

/**
 * _strdup - duplicate a string
 * @str: The string to be duplicated
 *
 * Return: the duplicated string
 */
char *_strdup(char *str)
{
	char *duplicated_string;
	int i;

	if (str == NULL)
		return (NULL);

	duplicated_string = malloc(sizeof(char) * (_strlen(str) + 1));
	if (duplicated_string == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		duplicated_string[i] = str[i];
	duplicated_string[i] = '\0';

	return (duplicated_string);
}
