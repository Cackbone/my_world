/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** my_str_isnum
*/

#include <my.h>
#include <macros.h>

int isnt_num_valid(char c, int has_number)
{
	if ((c == '-') || (c == '+') || (has_number))
		return (0);
	return (1);
}

int my_str_isnumvalid(char c, int *has_number)
{
	if (my_isnum(c))
		*has_number = 1;
	else {
		if (isnt_num_valid(c, *has_number))
			return (0);
	}
	return (1);
}

int my_str_isnum(char *str)
{
	int has_number = 0;

	for (int i = 0; str[i] != EOS; i++) {
		if (!my_str_isnumvalid(str[i], &has_number))
			return (0);
	}
	return (1);
}
