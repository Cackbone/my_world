/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** my_getnbr
*/

#include <my.h>

int my_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int check_int_limit(long val)
{
	if ((val >= -2147483648) && (val <= 2147483647))
		return ((int) val);
	return (0);
}

void get_int_value(char c, int *mul, long *value)
{
	if (c == '-')
		(*mul) *= -1;
	else if (my_isnum(c))
		*value = (*value) * 10 + (c - 48);
}

int my_getnbr(char *str)
{
	long value = 0;
	int mul = 1;

	for (int i = 0; str[i] != '\0'; i++) {
		if ((my_isnum(str[i])) || (str[i] == '-') || (str[i] == '+'))
			get_int_value(str[i], &mul, &value);
		else
			break;
	}
	value *= mul;
	return (check_int_limit(value));
}
