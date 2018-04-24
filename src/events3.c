/*
** EPITECH PROJECT, 2018
** events3.c
** File description:
** events3
*/

#include <game.h>

void on_escape(t_game *game)
{
	if (game->textbox) {
		game->textbox->on_quit(game);
		destroy_textbox(game->textbox);
		game->textbox = NULL;
	} else
		game->running = 0;
}

void on_switch_face_point(t_game *game)
{
	if (!(game->textbox)) {
		game->selection_mode = 1 - game->selection_mode;
		if (game->selected_face)
			game->selected_face->color = sfWhite;
		game->selected_face = NULL;
		game->selected_vertex = NULL;
		if (game->map)
			update_vertex_array(game);
	}
}

void on_rotate_face(t_game *game)
{
	t_face *f = NULL;

	if (game->selected_face && !(game->textbox)) {
		f = game->selected_face;
		f->rotation = (f->rotation + 1) % 4;
		update_vertex_array(game);
	}
}
