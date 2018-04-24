/*
** EPITECH PROJECT, 2018
** my_reset.c
** File description:
** my_reset
*/

#include <game.h>
#include <brush.h>
#include <my_world.h>

void my_free_move(t_game *game)
{
	if (game->scale && game->translate) {
		free(game->scale);
		free(game->translate);
	}
}

void my_reset(t_game *game, t_button UNUSED *button)
{
	t_map *map = game->map;
	char *filepath = NULL;

	if (!map)
		return;
	filepath = my_strdup(map->filepath);
	destroy_map(map);
	map = load_map(filepath, game);
	my_free_move(game);
	game->scale = create_vector3(50, 50, 25);
	game->translate = create_vector2(500, 200);
	if (!(game->scale) || !(game->translate) || !(game->map = map))
		update_state(game, "Error while loading");
	else {
		update_vertex_array(game);
		update_brush(game);
		update_state(game, "Map reset");
	}
}
