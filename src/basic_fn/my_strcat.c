/*
** EPITECH PROJECT, 2018
** str cat
** File description:
** str cat
*/

#include <my.h>
#include <stdlib.h>

char *my_strcat(char *s1, char *s2)
{
	int len_1 = my_strlen(s1);
	int len_2 = my_strlen(s2);
	char *str = malloc(len_1 + len_2 + 1);
	int i = 0;

	if (!str)
		return (NULL);
	if (s1)
		for (int j = 0; s1[j]; j++, i++)
			str[i] = s1[j];
	if (s2)
		for (int j = 0; s2[j]; j++, i++)
			str[i] = s2[j];
	str[len_1 + len_2] = 0;
	return (str);
}
