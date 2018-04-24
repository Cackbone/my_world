/*
** EPITECH PROJECT, 2018
** window.c
** File description:
** window
*/

#include <game.h>

sfRenderWindow *create_window(char *title, unsigned int fps)
{
	sfRenderWindow *win;
	sfVideoMode mode = sfVideoMode_getDesktopMode();

	win = sfRenderWindow_create(mode, title, sfFullscreen | sfClose, NULL);
	if (!win)
		return (NULL);
	sfRenderWindow_setFramerateLimit(win, fps);
	return (win);
}

void update_state(t_game *game, char *state)
{
	sfText_setString(game->ui->state_text, state);
	sfText_setColor(game->ui->state_text, sfRed);
}
