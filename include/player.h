/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** yudsqcoihfdyug
*/

#ifndef PLAYER_H_
#define PLAYER_H_

typedef struct s_game t_game;

typedef struct player_s {
	sfVector3f *position;
	sfVector2f *rotation;
} player_t;

player_t *create_player();
void move_player(struct s_game *);
void rotate_player(struct s_game *);
void destroy_player(struct player_s *);
#endif
