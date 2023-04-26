#include "shell.h"
/**
 * _getline - Reads an entire line from a file descriptor
 * @dbl: pointer to buffer to store the line
 * @boff: pointer to size of the buffer
 * @size: file descriptor.
 * Return: length of the line or -1 on failure
 */
size_t _getline(char **dbl, size_t *boff, int size)
{
	static char buff[BUFFER_SIZE];
	static size_t count, end_count;
	size_t lon = 0;
	ssize_t pld;

	if (dbl == NULL || boff == NULL)
		return (-1);

	if (*dbl == NULL)
	{
		*dbl = malloc(BUFFER_SIZE);
		if (*dbl == NULL)
			return (-1);
		*boff = BUFFER_SIZE;
	}
	while (1)
	{
		if (count >= end_count)
		{
			pld = read(size, buff, BUFFER_SIZE);
			if (pld <= 0)
				return (-1);

			count = 0;
			end_count = pld;
		}
		while (count < end_count)
		{
			if (lon >= *boff - 1)
			{
				(*dbl)[lon] = '\0';
				return (lon);
			}
			(*dbl)[lon++] = buff[count++];
			if ((*dbl)[lon - 1] == '\n')
			{
				(*dbl)[lon] = '\0';
				return (lon);
			}
		}
	}
}
