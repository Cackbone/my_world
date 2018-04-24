/*
** EPITECH PROJECT, 2018
** my_pause.c
** File description:
** my_pause
*/

#include <game.h>
#include <my_world.h>

void my_pause(t_game *game, t_button *button)
{
	game->playing = !(game->playing);
	if (game->playing) {
		sfText_setString(button->text, "Pause");
		update_state(game, "Game resumed");
	} else {
		sfText_setString(button->text, "Resume");
		update_state(game, "Game paused");
	}
}
