/*
** EPITECH PROJECT, 2018
** parser.c
** File description:
** parser
*/

#include <map.h>
#include <my_world.h>

int create_texture(t_map *map, char **res, int size)
{
	t_hashmap *hmap = map->textures;
	t_texture *tex = NULL;

	if (size == 6) {
		tex = malloc(sizeof(t_texture));
		if (!tex)
			return (1);
		tex->x = get_value(res[2]);
		tex->y = get_value(res[3]);
		tex->xsize = get_value(res[4]);
		tex->ysize = get_value(res[5]);
		tex->name = my_strdup(res[1]);
		hmap->add(my_concat(res[1], ""), tex);
		return (0);
	}
	return (1);
}

int load_texture(t_map *map, char **res, int size)
{
	char *path = NULL;

	if (size == 2) {
		path = my_concat("resources/img/", res[1]);
		map->tilemap = sfTexture_createFromFile(path, NULL);
		if (!(map->tilemap))
			return (1);
		map->tilemap_filepath = my_strdup(res[1]);
		map->states->texture = map->tilemap;
		free(path);
		return (0);
	}
	return (1);
}

int create_vertex(t_map *map, char **res, int size)
{
	t_vertex *vec = NULL;

	if (size == 4) {
		vec = malloc(sizeof(t_vertex));
		if (!vec)
			return (1);
		vec->x = get_value(res[1]);
		vec->y = get_value(res[2]);
		vec->z = get_value(res[3]);
		check_map_limit(map, vec);
		add_elem(map->vertices, vec);
		return (0);
	}
	return (1);
}

int parse_rotation(char **res)
{
	int size = get_array_size(res);
	char *s = NULL;
	int rot = 0;

	if (size == 7) {
		s = res[6];
		if ((s[0] == '-') && (s[1] == 'r') && my_str_isnum(s + 2))
			rot = my_getnbr(s + 2);
		else {
			my_puterr("Error: invalid flag ");
			my_puterr(s);
			my_puterr("\n");
		}
	}
	return (rot);
}

int create_face(t_map *map, char **res, int size)
{
	t_hashmap *hmap = map->textures;
	t_face *face = NULL;
	t_vertex **vertices = NULL;
	t_texture *texture = NULL;
	list_t *vs = map->vertices;

	if ((size == 6) || (size == 7)) {
		face = malloc(sizeof(t_face));
		vertices = malloc(sizeof(t_vertex *) * 4);
		texture = hmap->get(res[5]);
		if (!face || !vertices || !texture)
			return (1);
		for (int i = 0; i < 4; i++) {
			vertices[i] = get_elem(vs, get_value(res[i + 1]) - 1);
			if (!vertices[i])
				return (1);
		}
		init_face(face, vertices, texture);
		face->rotation = parse_rotation(res);
		add_elem(map->faces, face);
		return (0);
	}
	return (1);
}
