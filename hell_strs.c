#include "shell.h"

/**
 * _strcat - Concantenate two strings.
 * @dest: dest string.
 * @src: source string.
 *
 * Return: pointer.
 */
char *_strcat(char *dest, const char *src)
{
	const char *container1;
	char *container;

	container1 = src;
	container = dest;

	while (*container1 != '\0')
		container1++;

	while (*container !=  '\0')
		*container++ = *container1++;
	*container = '\0';
	return (dest);
}

/**
 * _strncmp - compares strings.
 * @str1: strings
 * @str2: strings
 * @count: string lenght.
 *
 * Return: 1 0r -1 if not the same.
 */
int _strncmp(char *str1, char *str2, unsigned int count)
{
	unsigned int mot;

	for (mot = 0; mot < count; mot++)
	{
		if (str1[mot] != str2[mot])
		{
			return (-1);
		}
	}
	return (1);
}

/**
 * _itoa - change int to str.
 * @b: variable to be coverted.
 *
 * Return: pointer.
 */
char *_itoa(int b)
{
	int count = 0, h = 0;
	char *bm;

	count = declen(b);
	bm = malloc(count + 1);

	if (!bm)
		return (NULL);
	*bm = '\0';
	while (b / 10)
	{
		bm[h] = (b % 10) + '0';
		b /= 10;
		h++;
	}
	bm[h] = (b % 10) + '0';
	arr(bm, count);
	bm[h + 1] = '\0';
	return (bm);
}

/**
 * declen - calculate the lenght of int.
 * @digit: variable.
 *
 * Return: lenght.
 */
int declen(int digit)
{
	int count;

	for (count = 0; num != 0; count++)
	{
		digit /= 10;
	}
	return (count);
}

/**
 * rev_arr - rev array.
 * @ar: array.
 * @size: lenght.
 *
 * Return: no return.
 */
void rev_arr(char *ar, int size)
{
	int h;
	char cont;

	while (h < (size / 2))
	{
		cont = ar[h];
		ar[h] = ar[(size - 1) - 1];
		ar[(size - 1) - h] = cont;
	}
}
