#include "shell.h"

/**
 * record - data.
 * @data: user data.
 *
 * Description: data
 * @Return: 0 or -1.
 */
int record(char *data)
{
	char *file_rec = ".record";
	ssize_t fd, pls;
	int count;

	if (!file_rec)
		return (-1);
	fd = open(file_rec, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (data)
	{
		while (data[count])
			count++;
		pls = write(fd, data, count);
		if (pls < 0)
			return (-1);
	}
	return (-1);
}

/**
 * record_print - print record.
 * @m: tokinised cmd.
 * @b: last cmd.
 *
 * Description: print record.
 * @Return: 0 or -1.
 */
int record_print(char *m, int b)
{
	char *file_rec = ".record";
	FILE *fd;
	char *row = NULL, *pal;
	size_t count = 0;
	int cont = 0;

	fd = fopen(file_rec, "r");
	if (fd == NULL)
	{
		return (-1);
	}
	while ((getline(&row, &count, fd)) != -1)
	{
		cont++;
		pal = _itoa(cont);
		PROMPT(pal);
		free(pal);
		PROMPT(" ");
		PROMPT(row);
	}
	if (row)
	{
		free(row);
	}
	fclose(fd);
	return (0);
}
