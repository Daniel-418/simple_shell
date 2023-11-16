#include "simple_shell.h"

#define BUFFER_SIZE 1024


/**
 * refill_buffer - refills a buffer
 * @buffer: the buffer
 * @buffer_size: the buffer size
 * @position: the position
 * @fd: the file descriptor
 *
 * Return: The buffer size
 */
static ssize_t refill_buffer(char *buffer, ssize_t *buffer_size,
		ssize_t *position, int fd)
{
	*buffer_size = read(fd, buffer, BUFFER_SIZE);
	*position = 0;
	return (*buffer_size);
}

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
	static ssize_t buffer_size, position;
	char *new_lineptr;
	size_t len = 0, j;
	ssize_t i;

	if (!lineptr || !n || fd < 0)
		return (-1);
	if (*lineptr == NULL)
		*lineptr = malloc((*n = BUFFER_SIZE));
	if (*lineptr == NULL)
		return (-1);
	while (1)
	{
		if (position >= buffer_size && refill_buffer(buffer,
					&buffer_size, &position, fd) <= 0)
			return (-1);
		for (i = position; i < buffer_size; i++)
		{
			if (len >= *n - 1)
			{
				new_lineptr = malloc(*n + BUFFER_SIZE);
				if (new_lineptr == NULL)
					return (-1);
				for (j = 0; j < len; j++)
					new_lineptr[j] = (*lineptr)[j];
				free(*lineptr);
				*lineptr = new_lineptr;
				*n += BUFFER_SIZE;
			}
			(*lineptr)[len++] = buffer[i];
			if (buffer[i] == '\n')
			{
				(*lineptr)[len] = '\0';
				position = i + 1;
				return (len);
			}
		}
		position = buffer_size;
	}
}
