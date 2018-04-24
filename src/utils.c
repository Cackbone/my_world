/*
** EPITECH PROJECT, 2018
** utils.c
** File description:
** utils
*/

#include <my_world.h>

int get_value(char *str)
{
	if (!str || !my_str_isnum(str)) {
		my_puterr("Error: bad value: ");
		my_puterr(str);
		my_puterr("\n");
		return (0);
	}
	return (my_getnbr(str));
}

char *clear_line(char *line)
{
	int size = 0;
	char *res = NULL;

	if (!line)
		return (NULL);
	if (EQUALS(line, "\n") || EQUALS(line, "\0") || line[0] == '#') {
		free(line);
		return (NULL);
	}
	for (size = 0; line[size] && line[size] != '#'; size++);
	res = malloc(sizeof(char) * (size + 1));
	for (int i = 0; i < size; i++)
		res[i] = line[i];
	res[size] = 0;
	free(line);
	return (res);
}

void check_map_limit(t_map *map, t_vertex *vec)
{
	if (vec->x > map->x_size)
		map->x_size = vec->x;
	if (vec->y > map->y_size)
		map->y_size = vec->y;
	if (vec->z > map->z_size)
		map->z_size = vec->z;
}
