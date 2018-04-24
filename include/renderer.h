/*
** EPITECH PROJECT, 2018
** renderer.h
** File description:
** renderer
*/

#ifndef RENDERER_H_
#define RENDERER_H_

#include <my_world.h>

typedef struct s_game t_game;
typedef struct s_face t_face;

t_face *copy_face(t_face *);
list_t *copy_faces(list_t *);
sfVector3f get_middle_face(t_face *);
float distance(t_face *, sfVector3f *);
list_t *sort_faces(t_game *game);

list_t *shell_sort(list_t *, sfVector3f *);

#endif
