/*
** EPITECH PROJECT, 2018
** map.c
** File description:
** map
*/

#include <game.h>
#include <parser.h>
#include <my_world.h>

t_map *create_map(char *filepath)
{
	t_map *map = malloc(sizeof(t_map));
	sfRenderStates *states = malloc(sizeof(sfRenderStates));
	list_t *vertices = create_list();
	list_t *faces = create_list();
	t_hashmap *textures = create_hashmap();

	if (!map || !states || !vertices || !faces || !textures)
		return (NULL);
	map->vertices = vertices;
	map->faces = faces;
	map->textures = textures;
	map->tilemap = NULL;
	map->filepath = filepath;
	map->states = states;
	states->shader = NULL;
	states->transform = sfTransform_Identity;
	states->texture = NULL;
	states->blendMode = sfBlendAlpha;
	return (map);
}

int parse_line(t_map *map, char *line)
{
	char **res = my_strsplit(line, " ");
	t_parser *parser = NULL;
	int size = 0;

	if (!res)
		return (0);
	size = get_array_size(res);
	for (int i = 0; i < PARSER_COUNT; i++) {
		parser = (t_parser *) &(PARSERS[i]);
		if (EQUALS(res[0], parser->name))
			return (parser->func(map, res, size));
	}
	my_free_array(res);
	return (1);
}

int load_file(t_map *map, FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;

	nread = getline(&line, &len, file);
	while (nread != -1) {
		if (line[nread - 1] != 0)
			line[nread - 1] = 0;
		line = clear_line(line);
		if (line) {
			if (parse_line(map, line))
				return (0);
			free(line);
			line = NULL;
		}
		nread = getline(&line, &len, file);
	}
	return (1);
}

t_map *load_map(char *filepath, t_game *game)
{
	FILE *file = fopen(filepath, "r");
	t_map *map = NULL;

	if (!file)
		return (NULL);
	update_state(game, 0);
	map = create_map(filepath);
	if (!map)
		return (NULL);
	map->x_size = 0;
	map->y_size = 0;
	map->z_size = 0;
	if (!load_file(map, file))
		map = NULL;
	return (map);
}
