/*
** EPITECH PROJECT, 2018
** my_free_array.c
** File description:
** my_free_array
*/

#include <stdlib.h>

void my_free_array(char **tab)
{
	for (int i = 0; tab[i] != NULL; i++)
		free(tab[i]);
	free(tab);
}
