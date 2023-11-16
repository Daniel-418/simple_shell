#include "simple_shell.h"

#define BUFFER_SIZE 1024

/**
 * _getline - custom getline function implementation
 * @lineptr: pointer to the buffer containing read line
 * @n: size of the buffer
 * @fd: file descriptor from which to read
 *
 * Return: number of characters read, -1 on failure or EOF
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	static char buffer[BUFFER_SIZE];
	static ssize_t buffer_size = 0;
	static ssize_t position = 0;
	size_t len = 0;
	size_t j;
	ssize_t i;
	char *new_lineptr;

	if (!lineptr || !n || fd < 0)
		return -1;
	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
			return -1;
	}
	while (1)
	{
		if (position >= buffer_size)
		{
			buffer_size = read(fd, buffer, BUFFER_SIZE);
			if (buffer_size <= 0)
				return buffer_size;
			position = 0;
		}
		for (i = position; i < buffer_size; i++)
		{
			if (len >= *n - 1)
			{
				new_lineptr = malloc(*n + BUFFER_SIZE);
				if (new_lineptr == NULL)
					return -1;
				for (j = 0; j < len; j++)
				{
					new_lineptr[j] = (*lineptr)[j];
				}
				free(*lineptr);
				*lineptr = new_lineptr;
				*n += BUFFER_SIZE;
			}
			(*lineptr)[len++] = buffer[i];
			if (buffer[i] == '\n')
			{
				position = i + 1;
				(*lineptr)[len] = '\0';
				return len;
			}
		}
		position = buffer_size;
	}
}

