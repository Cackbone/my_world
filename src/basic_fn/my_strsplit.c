/*
** EPITECH PROJECT, 2018
** my_strsplit.c
** File description:
** my_strsplit
*/

#include <my.h>
#include <macros.h>
#include <unistd.h>
#include <stdlib.h>

int count_noregex(char *str, char *regex)
{
	int cnt = 0;
	int rlen = my_strlen(regex);
	int last = -rlen;

	for (int i = 0; str[i] != EOS; i++) {
		if (start_by(str + i, regex)) {
			if (last + rlen != i)
				cnt++;
			i += rlen - 1;
			last = i;
		}
	}
	if (last != my_strlen(str))
		cnt++;
	return (cnt);
}

void complete_tab(char **res, char *str, int *data)
{
	if (data[0] + data[1] != data[2]) {
		res[data[3]] = my_substring(str, data[0] + data[1], data[2]);
		data[3]++;
	}
}

char **my_strsplit(char *str, char *regex)
{
	int cnt = count_noregex(str, regex);
	char **res = malloc(sizeof(char *) * (cnt + 1));
	int rlen = my_strlen(regex);
	int size = my_strlen(str);
	int data[4] = {-rlen, rlen, 0, 0};

	if (!res)
		return (NULL);
	for (int i = 0; str[i] != EOS; i++) {
		data[2] = i;
		if (start_by(str + i, regex)) {
			complete_tab(res, str, data);
			i += rlen - 1;
			data[0] = i;
		}
	}
	if (data[0] != size)
		res[cnt - 1] = my_substring(str, data[0] + rlen, size);
	res[cnt] = NULL;
	return (res);
}
