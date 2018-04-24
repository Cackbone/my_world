/*
** EPITECH PROJECT, 2018
** my_load.c
** File description:
** my_load
*/

#include <map.h>
#include <game.h>
#include <button.h>
#include <brush.h>

void after_load(t_game *game)
{
	if (game->scale && game->translate) {
		free(game->scale);
		free(game->translate);
	}
	game->scale = create_vector3(50, 50, 25);
	game->translate = create_vector2(500, 200);
	game->selection_mode = FACE;
	game->selected_face = NULL;
	game->selected_vertex = NULL;
	update_state(game, "Map loaded");
	update_vertex_array(game);
	update_brush(game);
}

void load_enter(t_game *game, char *str)
{
	t_map *map = game->map;
	t_map *tmp = NULL;
	char *filepath = my_strcat("resources/maps/", str);
	char *path = my_strcat(filepath, ".legend");

	free(filepath);
	game->ui->ui_pause = 0;
	destroy_textbox(game->textbox);
	game->textbox = NULL;
	tmp = load_map(path, game);
	if (tmp) {
		if (map)
			destroy_map(map);
		game->map = tmp;
		after_load(game);
	} else
		update_state(game, "Error while loading map");
}

void load_quit(t_game *game)
{
	game->ui->ui_pause = 0;
}

void my_load(t_game *game, t_button UNUSED *button)
{
	t_textbox *box = create_textbox("Filename: ", 20);

	box->on_enter = load_enter;
	box->on_quit = load_quit;
	game->textbox = box;
	game->ui->ui_pause = 1;
}
