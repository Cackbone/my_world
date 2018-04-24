/*
** EPITECH PROJECT, 2018
** events.h
** File description:
** events
*/

#ifndef EVENTS_H_
#define EVENTS_H_

#include <game.h>

void on_escape(t_game *);
void on_switch_face_point(t_game *);
void on_rotate_face(t_game *);

void events(t_game *);
void moves_keys(t_game *);
void zoom_keys(t_game *);

#endif
