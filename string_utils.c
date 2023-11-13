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

/**
 * _strcmp - Compares two strings.
 * @str1: First string for comparison.
 * @str2: Second string for comparison.
 *
 * Return: An integer less than, equal to,
 * or greater than zero if str1 is found,
 * respectively, to be less than, to match,
 * or be greater than str2.
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return ((int)(*str1 - *str2));
}

/**
 * _strcat - concatenates two strings together
 * @str1: The first string
 * @str2: The second string
 *
 * Return: The concatenated string(must be freed)
 */
char *_strcat(char *str1, char *str2)
{
	char *concatenated_string;
	int i, j, len_str1, len_str2;

	if (str1 == NULL || str2 == NULL)
		return (NULL);

	len_str1 = _strlen(str1);
	len_str2 = _strlen(str2);
	concatenated_string = malloc(sizeof(char) * (len_str1 + len_str2 + 1));

	for (i = 0; i < len_str1; i++)
		concatenated_string[i] = str1[i];

	for (j = 0; str2[j] != '\0'; j++)
		concatenated_string[i + j] = str2[j];

	concatenated_string[i + j] = '\0';

	return (concatenated_string);
}
