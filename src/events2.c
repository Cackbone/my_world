/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** ui
*/

#include <game.h>

void zoom_keys(t_game *game)
{
	if (!(game->scale) || (game->textbox))
		return;
	switch ((int)game->event->key.code) {
	case sfKeyA:
		sfView_zoom(game->view, 0.9);
		break;
	case sfKeyZ:
		sfView_zoom(game->view, 1.1);
		break;
	default:
		break;
	}
}
