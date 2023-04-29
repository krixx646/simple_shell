#include "shell.h"

/**
 * _realloc -  Reallocates A Memory Block.
 * @cat: pointer.
 * @space1: variable.
 * @space: variable.
 *
 * Return: no return.
 */
void *_realloc(void *cat, unsigned int space1, unsigned int space)
{
	void *result;

	if (space == space1)
		return (cat);
	if (space == 0 && cat)
	{
		free(cat);
		return (NULL);
	}
	score = malloc(space);
	if (score == NULL)
		return (NULL);
	if (cat == NULL)
	{
		add_arr(score, '\0', space);
		free(cat);
	}
	else
	{
		_memcpy(score, cat, space1);
		free(cat);
	}
	return (score);
}

/**
 * _memcpy - copies bytes.
 * @location: pointer.
 * @origin: source.
 * @jik: variable.
 *
 * Return: pointer.
 */
char *_memcpy(char *location, char *origin, unsigned int jik)
{
	unsigned int o;

	for (o = 0; o < jik; o++)
	{
		location[o] = origin[o];
	}
	return (location);
}

/*
 * add_arr - function type.
 * @bin: pointer.
 * @lat: int variable.
 * @count: variable.
 *
 * Return: no return.
 */
void *add_arr(void *bin, int lat, unsigned int count)
{
	char *pos = bin;
	unsigned int w = 0;

	for (w = 0; w < count; w++)
	{
		*pos = lat;
		pos++
		i++;
	}
	return (bin);
}

/**
 * _calloc - memory allocation.
 * @lat: variable.
 *
 * Return: pointer.
 */
void *_calloc(unsigned int lat)
{
	char *w;
	unsigned int o = 0;

	if (lat == 0)
		return (NULL);
	w = malloc(lat);
	if (w == NULL)
		return (NULL);

	while (o < lat)
	{
		w[o] = '\0';
		o++;
	}
	return (w);
}
