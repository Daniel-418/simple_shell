#include "simple_shell.h"

/** _strlen - counts the number of letters in a string
 * @str: The string
 *
 * Return: the numbers of letters in the string
 */
size_t _strlen(const char *str)
{
	size_t count;

	if (str == NULL)
		return (-1);

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}

	return (count);
}
