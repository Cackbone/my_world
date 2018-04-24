/*
** EPITECH PROJECT, 2018
** my_texture.c
** File description:
** my_texture
*/

#include <game.h>
#include <brush.h>

void my_texture(t_game *game, t_button UNUSED *button)
{
	if (game->paint) {
		game->paint = 0;
		game->brush = NULL;
	} else if (game->map) {
		game->paint = 1;
		update_brush(game);
	}
}
