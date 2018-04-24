/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** ui
*/

#include <game.h>

void zoom_in(t_game *game)
{
	float sx = game->scale->x;
	float sy = game->scale->y;
	float sz = game->scale->z;

	if (sx > 0 && sy > 0 && sz > 0) {
		game->scale->x--;
		game->scale->y--;
		game->scale->z -= 0.5;
		update_vertex_array(game);
	}
}

void zoom_keys(t_game *game)
{
	if (!(game->scale) || (game->textbox))
		return;
	switch ((int)game->event->key.code) {
	case sfKeyA:
		game->scale->x++;
		game->scale->y++;
		game->scale->z += 0.5;
		update_vertex_array(game);
		break;
	case sfKeyZ:
		zoom_in(game);
		break;
	default:
		break;
	}
}
