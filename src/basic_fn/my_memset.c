/*
** EPITECH PROJECT, 2018
** my_memset.c
** File description:
** my_memset
*/

void my_memset(char *str, char c, int size)
{
	for (int i = 0; i < size; i++)
		str[i] = c;
}
