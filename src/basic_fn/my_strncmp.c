/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	for (; s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1; i++);
	return (s1[i] - s2[i]);
}
