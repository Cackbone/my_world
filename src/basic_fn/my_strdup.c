/*
** EPITECH PROJECT, 2018
** my_strdup.c
** File description:
** my_strdup
*/

#include <my.h>
#include <stdlib.h>

char *my_strdup(char *str)
{
	int size = my_strlen(str);
	char *res = malloc(sizeof(char) * (size + 1));

	for (int i = 0; i < size; i++)
		res[i] = str[i];
	res[size] = 0;
	return (res);
}
