/*
** EPITECH PROJECT, 2018
** my_array_utils.c
** File description:
** my_array_utils
*/

#include <my.h>
#include <macros.h>
#include <stdlib.h>

int my_strlen(char *str)
{
	int i = 0;

	for (; str[i]; i++);
	return (i);
}

char *my_strncpy(char *dest, char *src, int n)
{
	int src_size = my_strlen(src);
	int to = MIN(src_size, n);

	for (int i = 0; i < to; i++)
		dest[i] = src[i];
	return (dest);
}

char *my_substring(char *str, int start, int end)
{
	int size = end - start;
	char *res = malloc(sizeof(char) * (size + 1));

	if (!res)
		return (NULL);
	my_strncpy(res, str + start, size);
	res[size] = 0;
	return (res);
}

int start_by(char *container, char *str)
{
	int len_c = my_strlen(container);
	int len_s = my_strlen(str);

	if (len_c < len_s)
		return (0);
	for (int i = 0; container[i] && str[i]; i++)
		if (container[i] != str[i])
			return (0);
	return (1);
}

int get_array_size(char **array)
{
	int i = 0;

	for (; array[i] != NULL; i++);
	return (i);
}
