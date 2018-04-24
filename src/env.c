/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** my_world
*/

#include <my.h>
#include <stdio.h>

int check_env(char **env)
{
	if (!env)
		return (0);
	for (int i = 0; env[i]; i++) {
		if (my_strncmp(env[i], "DISPLAY", 7) == 0)
			return (1);
	}
	return (0);
}
