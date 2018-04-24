/*
** EPITECH PROJECT, 2018
** selector.h
** File description:
** selector
*/

#ifndef SELECTOR_H_
#define SELECTOR_H_

#include <SFML/System.h>

typedef struct s_game t_game;
typedef struct s_vertex t_vertex;

void select_face(t_game *);
int is_in_circle(t_vertex *, sfVector2f *, float);
t_vertex *get_selected_vertex(t_game *);
void select_point(t_game *);

#endif
