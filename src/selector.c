/*
** EPITECH PROJECT, 2018
** selector.c
** File description:
** selector
*/

#include <game.h>
#include <my_world.h>
#include <selector_def.h>

void select_face(t_game *game)
{
	sfRenderWindow *win = game->window;
	sfView *view = game->view;
	sfVector2i mousei = sfMouse_getPositionRenderWindow(win);
	sfVector2f mouse = sfRenderWindow_mapPixelToCoords(win, mousei, view);
	list_node_t *node = NULL;
	t_face *face = NULL;

	if (game && game->map && game->map->faces) {
		node = game->map->faces->first;
		while (node) {
			((t_face *) node->data)->color = sfWhite;
			if (face_contain(&mouse, node->data))
				face = node->data;
			node = node->next;
		}
		if (face)
			face->color = FACE_COLOR;
		game->selected_face = face;
		update_vertex_array(game);
	}
}

int is_in_circle(t_vertex *point, sfVector2f *mouse, float dist)
{
	sfVector2f p = point->projected;
	float dx = p.x - mouse->x;
	float dy = p.y - mouse->y;
	float d = sqrtf(dx * dx + dy * dy);

	return (d <= dist);
}

t_vertex *get_selected_vertex(t_game *game)
{
	sfRenderWindow *win = game->window;
	sfView *view = game->view;
	sfVector2i mousei = sfMouse_getPositionRenderWindow(win);
	sfVector2f mouse = sfRenderWindow_mapPixelToCoords(win, mousei, view);
	list_node_t *node = NULL;
	t_vertex *vertex = NULL;

	if (game && game->map && game->map->vertices) {
		node = game->map->vertices->first;
		while (node) {
			if (is_in_circle(node->data, &mouse, 40))
				vertex = node->data;
			node = node->next;
		}
	}
	return (vertex);
}

void select_point(t_game *game)
{
	t_vertex *vertex = NULL;
	sfVector2f tmp = {0, 0};

	vertex = get_selected_vertex(game);
	if ((game->selected_vertex = vertex)) {
		tmp.x = vertex->projected.x - 8;
		tmp.y = vertex->projected.y - 8;
		sfSprite_setPosition(game->selection_sprite, tmp);
	}
}
