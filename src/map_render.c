/*
** EPITECH PROJECT, 2018
** map_render.c
** File description:
** map_render
*/

#include <game.h>

void init_face(t_face *face, t_vertex **vertices, t_texture *texture)
{
	face->array = NULL;
	face->grid = NULL;
	face->color = sfWhite;
	face->vertices = vertices;
	face->texture = texture;
}

void my_selection(t_game *game, float add)
{
	if (game->paint) {
		game->selected_face->texture = game->brush;
		update_vertex_array(game);
	} else {
		for (int i = 0; i < 4; i++)
			game->selected_face->vertices[i]->z += add;
		update_vertex_array(game);
	}
}

void render_face(t_game *game, t_face *face)
{
	sfRenderStates *st = game->map->states;
	sfRenderWindow *win = game->window;
	sfSprite *ss = game->selection_sprite;

	sfRenderWindow_drawVertexArray(win, face->array, st);
	for (int i = 0; i < 4; i++)
		if (face->vertices[i] == game->selected_vertex)
			sfRenderWindow_drawSprite(win, ss, NULL);
	sfRenderWindow_drawVertexArray(win, face->grid, NULL);
}

void render_map(t_game *game)
{
	list_node_t *tmp = NULL;
	t_face *face = NULL;

	if (!game->map)
		return;
	tmp = game->map->render_faces->first;
	while (tmp != NULL) {
		face = tmp->data;
		render_face(game, face);
		tmp = tmp->next;
	}
}
