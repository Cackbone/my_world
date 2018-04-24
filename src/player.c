/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** opengl
*/
#include <my_world.h>
#include <player.h>

player_t *create_player(void)
{
	player_t *player = malloc(sizeof(player_t));
	sfVector3f *position = create_vector3(0, 0, 0);
	sfVector2f *rotation = create_vector2(0, 0);

	if (!player || !rotation || !position)
		return (NULL);
	player->position = position;
	player->rotation = rotation;
	return (player);
}

void destroy_player(player_t *player)
{
	if (player) {
		free(player->position);
		free(player->rotation);
		free(player);
	}
}
