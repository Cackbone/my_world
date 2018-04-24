/*
** EPITECH PROJECT, 2018
** button_defs.h
** File description:
** button_defs
*/

#ifndef BUTTONS_DEFS_H_
#define BUTTONS_DEFS_H_

#include <game.h>
#include <stdlib.h>
#include <button.h>

void my_load(t_game *, t_button *);
void my_pause(t_game *, t_button *);
void my_reset(t_game *, t_button *);
void my_save(t_game *, t_button *);
void my_quit(t_game *, t_button *);
void my_texture(t_game *, t_button *);

const int X_POSITIONS[7] = { 100, 100, 100, 100, 100, 100 };
const int Y_POSITIONS[7] = { 50, 200, 350, 500, 650, 850 };
const int X_SIZES[7] = { 300, 300, 300, 300, 300, 300 };
const int Y_SIZES[7] = { 100, 100, 100, 100, 100, 100 };
const but_action ACTIONS[7] = { my_load,
				my_save,
				my_texture,
				my_reset,
				my_pause,
				my_quit};

#endif
