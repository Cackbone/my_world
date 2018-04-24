/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include <game.h>
#include <events.h>

int main(UNUSED int argc, UNUSED char **argv, char **envp)
{
	t_game *game;

	if (!(check_env(envp)) || !(game = create_game()))
		return (84);
	while (game->running && sfRenderWindow_isOpen(game->window)) {
		events(game);
		sfRenderWindow_clear(game->window, game->skybox);
		update_game(game);
		render_game(game);
		sfRenderWindow_display(game->window);
	}
	if (game) {
		if (game->map)
			save_map(game, my_concat(game->map->filepath, "~"));
		destroy_game(game);
	}
	return (0);
}
