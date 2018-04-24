/*
** EPITECH PROJECT, 2018
** transform.h
** File description:
** transform
*/

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include <map.h>
#include <SFML/System.h>

int line_intersect(sfVector2f *, sfVector2f *, sfVector2f *);
int vertex_contain(sfVector2f *, sfVector2f *);
int face_contain(sfVector2f *, t_face *);
sfVector2f *get_face_projected(t_face *);

#endif
