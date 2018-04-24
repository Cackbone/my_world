/*
** EPITECH PROJECT, 2018
** my_save.c
** File description:
** my_save
*/

#include <game.h>
#include <my_world.h>

void save_enter(t_game *game, char *str)
{
	char *filepath = my_strcat("resources/maps/", str);
	char *path = my_strcat(filepath, ".legend");

	free(filepath);
	game->ui->ui_pause = 0;
	destroy_textbox(game->textbox);
	game->textbox = NULL;
	if (game && game->map) {
		save_map(game, path);
		update_state(game, "Map saved");
	}
	else {
		update_state(game, "Map empty");
	}
}

void save_quit(t_game *game)
{
	game->ui->ui_pause = 0;
}

void my_save(t_game *game, t_button UNUSED *button)
{
	t_textbox *box = create_textbox("Filename: ", 20);

	box->on_enter = save_enter;
	box->on_quit = save_quit;
	game->textbox = box;
	game->ui->ui_pause = 1;
}
