/*
** EPITECH PROJECT, 2018
** map_saver.c
** File description:
** map_saver
*/

#include <map.h>
#include <game.h>
#include <my_world.h>

void save_vertices(int fd, t_map *map)
{
	list_node_t *node = map->vertices->first;
	t_vertex *pos = NULL;
	int index = 0;

	while (node) {
		pos = node->data;
		pos->id = index;
		write(fd, "v ", 2);
		my_put_nbr(fd, pos->x);
		write(fd, " ", 1);
		my_put_nbr(fd, pos->y);
		write(fd, " ", 1);
		my_put_nbr(fd, pos->z);
		write(fd, "\n", 1);
		index++;
		node = node->next;
	}
}

void save_textures(int fd, t_map *map)
{
	list_node_t *node = map->textures->list->first;
	t_hmap_node *hmap_node = NULL;
	t_texture *tex = NULL;

	while (node) {
		hmap_node = node->data;
		tex = hmap_node->value;
		write(fd, "t ", 2);
		write(fd, tex->name, my_strlen(tex->name));
		write(fd, " ", 1);
		my_put_nbr(fd, (int) tex->x);
		write(fd, " ", 1);
		my_put_nbr(fd, (int) tex->y);
		write(fd, " ", 1);
		my_put_nbr(fd, (int) tex->xsize);
		write(fd, " ", 1);
		my_put_nbr(fd, (int) tex->ysize);
		write(fd, "\n", 1);
		node = node->next;
	}
}

void save_faces(int fd, t_map *map)
{
	list_node_t *node = map->faces->first;
	t_face *face = NULL;

	while (node) {
		face = node->data;
		write(fd, "f ", 2);
		for (int i = 0; i < 4; i++) {
			my_put_nbr(fd, face->vertices[i]->id + 1);
			write(fd, " ", 1);
		}
		write(fd, face->texture->name, my_strlen(face->texture->name));
		if (face->rotation) {
			write(fd, " -r", 3);
			my_put_nbr(fd, face->rotation);
		}
		write(fd, "\n", 1);
		node = node->next;
	}
}

void save_map(t_game *game, char *file)
{
	int perm = O_WRONLY | O_CREAT | O_TRUNC;
	t_map *map = game->map;
	int fd = open(file, perm, 0664);
	char *tmfp = NULL;

	if (fd == -1)
		update_state(game, "Error while saving");
	else {
		tmfp = map->tilemap_filepath;
		write(fd, "tm ", 3);
		write(fd, tmfp, my_strlen(tmfp));
		write(fd, "\n\n", 2);
		save_vertices(fd, map);
		write(fd, "\n", 1);
		save_textures(fd, map);
		write(fd, "\n", 1);
		save_faces(fd, map);
		close(fd);
	}
}
