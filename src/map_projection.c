/*
** EPITECH PROJECT, 2018
** map_projection.c
** File description:
** map_projection
*/

#include <game.h>

sfVector2f project_point(t_vertex *p, t_game *game)
{
	sfVector2f pt = {0, 0};
	sfVector2f *a = game->angle;
	sfVector3f *s = game->scale;
	sfVector2f *t = game->translate;
	float x = p->x * s->x - game->player->position->x;
	float y = p->y * s->y - game->player->position->y;
	float z = p->z * s->z - game->player->position->z;

	pt.x = cos(a->x) * (x - y) + t->x;
	pt.y = sin(a->y) * (y + x) - z + t->y;
	return (pt);
}

void init_projection(t_game *game)
{
	list_node_t *node = game->map->vertices->first;
	t_vertex *v = NULL;

	while (node) {
		v = node->data;
		v->projected = project_point(v, game);
		node = node->next;
	}
}

void create_quad(t_face *face)
{
	t_texture *tex = face->texture;
	sfVector2f t0 = {tex->x, tex->y};
	sfVector2f t1 = {tex->x + tex->xsize, tex->y};
	sfVector2f t2 = {tex->x + tex->xsize, tex->y + tex->ysize};
	sfVector2f t3 = {tex->x, tex->y + tex->ysize};
	sfVector2f *p = get_face_projected(face);
	sfVertex v[4] = {
		{.position = p[1], .texCoords = ROT(&t1), .color = face->color},
		{.position = p[0], .texCoords = ROT(&t0), .color = face->color},
		{.position = p[2], .texCoords = ROT(&t2), .color = face->color},
		{.position = p[3], .texCoords = ROT(&t3), .color = face->color}
	};

	for (int i = 0; i < 4; i++)
		sfVertexArray_append(face->array, v[i]);
	sfVertexArray_setPrimitiveType(face->array, sfTrianglesStrip);
}

void create_lines(t_face *face)
{
	t_vertex **vs = face->vertices;
	sfVertex v0 = {.position = vs[0]->projected, .color = sfBlack};
	sfVertex v1 = {.position = vs[1]->projected, .color = sfBlack};
	sfVertex v2 = {.position = vs[2]->projected, .color = sfBlack};
	sfVertex v3 = {.position = vs[3]->projected, .color = sfBlack};

	sfVertexArray_append(face->grid, v0);
	sfVertexArray_append(face->grid, v1);
	sfVertexArray_append(face->grid, v1);
	sfVertexArray_append(face->grid, v2);
	sfVertexArray_append(face->grid, v2);
	sfVertexArray_append(face->grid, v3);
	sfVertexArray_append(face->grid, v3);
	sfVertexArray_append(face->grid, v0);
	sfVertexArray_setPrimitiveType(face->grid, sfLinesStrip);
}

void update_vertex_array(t_game *game)
{
	t_map *map = game->map;
	list_node_t *tmp = NULL;
	t_face *face = NULL;

	init_projection(game);
	tmp = map->faces->first;
	while (tmp != NULL) {
		face = tmp->data;
		if (face->array)
			sfVertexArray_destroy(face->array);
		if (face->grid)
			sfVertexArray_destroy(face->grid);
		face->array = sfVertexArray_create();
		face->grid = sfVertexArray_create();
		if (!face->array || !face->grid) {
			update_state(game, "Map loading failed");
			return;
		}
		create_quad(face);
		create_lines(face);
		tmp = tmp->next;
	}
	map->render_faces = map->faces;
	map->render_faces = sort_faces(game);
}
