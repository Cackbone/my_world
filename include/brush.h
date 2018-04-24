/*
** EPITECH PROJECT, 2018
** brush.h
** File description:
** brush
*/

#ifndef BRUSH_H_
#define BRUSH_H_

#include <game.h>

int init_brush(t_game *);
int update_brush(t_game *);
void switch_brush(t_game *);
void update_texture(t_game *, list_node_t *);
void display_brush(t_game *);

#endif
