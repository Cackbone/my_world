/*
** EPITECH PROJECT, 2018
** events.c
** File description:
** events
*/

#include <game.h>
#include <brush.h>
#include <events.h>

void moves_keys(t_game *game)
{
	sfVector2f mv_vec = {0, 0};

	switch ((int) game->event->key.code) {
	case sfKeyRight:
		mv_vec.x = -10;
		break;
	case sfKeyDown:
		mv_vec.y = -10;
		break;
	case sfKeyUp:
		mv_vec.y = 10;
		break;
	case sfKeyLeft:
		mv_vec.x = 10;
		break;
	default:
		break;
	}
	sfView_move(game->view, mv_vec);
}

void manage_keys(t_game *game)
{
	switch ((int) game->event->key.code) {
	case sfKeyEscape:
		on_escape(game);
		break;
	case sfKeyP:
		if (!game->textbox)
			on_switch_face_point(game);
		break;
	case sfKeyR:
		on_rotate_face(game);
		break;
	case sfKeyT:
		if (game->map && game->paint && !(game->textbox))
			switch_brush(game);
		break;
	default:
		break;
	}
}

void manage_mouse(t_game *game)
{
	if (game && !(game->textbox)) {
		if (game->selection_mode == FACE)
			select_face(game);
		else if (game->selection_mode == POINT)
			select_point(game);
	}
}

void manage_click(t_game *game, float add)
{
	sfVector2f tmp = {0, 0};

	if (game->textbox)
		return;
	if (game->selection_mode == FACE) {
		if (game->selected_face)
			my_selection(game, add);
	} else if (game->selection_mode == POINT) {
		if (game->selected_vertex) {
			game->selected_vertex->z += add;
			update_vertex_array(game);
			tmp.x = game->selected_vertex->projected.x - 8;
			tmp.y = game->selected_vertex->projected.y - 8;
			sfSprite_setPosition(game->selection_sprite, tmp);
		}
	}
}

void events(t_game *game)
{
	while (sfRenderWindow_pollEvent(game->window, game->event)) {
		if (game->event->type == sfEvtClosed)
			game->running = 0;
		else if (game->event->type == sfEvtKeyPressed) {
			update_textbox(game);
			manage_keys(game);
			moves_keys(game);
			zoom_keys(game);
		}
		if (game->event->type == sfEvtMouseMoved)
			manage_mouse(game);
	}
	if (sfMouse_isButtonPressed(sfMouseLeft))
		manage_click(game, 0.1);
	else if (sfMouse_isButtonPressed(sfMouseRight))
		manage_click(game, -0.1);
}
