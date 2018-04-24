/*
** EPITECH PROJECT, 2018
** my_concat.c
** File description:
** my_concat
*/

#include <my.h>
#include <macros.h>
#include <stdlib.h>

char *my_concat(char *a, char *b)
{
	int len_a = my_strlen(a);
	int len_b = my_strlen(b);
	char *res = malloc(sizeof(char) * (len_a + len_b + 1));

	for (int i = 0; i < len_a; i++)
		res[i] = a[i];
	for (int i = 0; i < len_b; i++)
		res[i + len_a] = b[i];
	res[len_a + len_b] = EOS;
	return (res);
}
