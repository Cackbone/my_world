/*
** EPITECH PROJECT, 2018
** renderer.c
** File description:
** renderer
*/

#include <game.h>
#include <renderer.h>

t_face *copy_face(t_face *f)
{
	t_face *cpy = malloc(sizeof(t_face));

	if (!cpy)
		return (NULL);
	cpy->texture = f->texture;
	cpy->vertices = f->vertices;
	cpy->rotation = f->rotation;
	cpy->array = f->array;
	cpy->grid = f->grid;
	return (cpy);
}

list_t *copy_faces(list_t *faces)
{
	list_t *res = create_list();
	list_node_t *node = NULL;

	if (!res || !faces)
		return (NULL);
	node = faces->first;
	while (node) {
		add_elem(res, copy_face(node->data));
		node = node->next;
	}
	return (res);
}

sfVector3f get_middle_face(t_face *f)
{
	sfVector3f res = {0, 0, 0};

	for (int i = 0; i < 4; i++) {
		res.x += f->vertices[i]->x;
		res.y += f->vertices[i]->y;
		res.z += f->vertices[i]->z;
	}
	res.x /= 4;
	res.y /= 4;
	res.z /= 4;
	return (res);
}

float distance(t_face *f, sfVector3f *player)
{
	sfVector3f fpos = get_middle_face(f);
	float x = fpos.x - player->x;
	float y = fpos.y - player->y;

	return (sqrtf(x * x + y * y));
}

list_t *sort_faces(t_game *game)
{
	t_map *map = game->map;
	list_t *copy = NULL;

	if (!map)
		return (NULL);
	copy = copy_faces(map->faces);
	if (!copy)
		return (NULL);
	return (shell_sort(copy, game->player->position));
}
