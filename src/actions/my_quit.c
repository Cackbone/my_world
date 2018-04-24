/*
** EPITECH PROJECT, 2018
** my_quit.c
** File description:
** my_quit
*/

#include <game.h>
#include <my_world.h>

void my_quit(t_game *game, t_button UNUSED *button)
{
	game->running = 0;
}
