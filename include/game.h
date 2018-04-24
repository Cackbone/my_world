/*
** EPITECH PROJECT, 2018
** game.h
** File description:
** game
*/

#ifndef GAME_H_
#define GAME_H_

#include <map.h>
#include <math.h>
#include <player.h>
#include <textbox.h>

#define TO_RAD(val) (val * M_PI / 180)
#define ROT(val2) rotate_texture(face, val2)

typedef enum e_selection_mode {
	POINT = 0,
	FACE
} t_selection_mode;

typedef struct s_game {
	t_map *map;
	t_map *grid;
	sfRenderWindow *window;
	sfEvent *event;
	sfView *view;
	int running;
	sfColor skybox;
	sfVector3f *scale;
	sfVector2f *angle;
	sfVector2f *translate;
	player_t *player;
	t_ui *ui;
	int playing;
	t_face *selected_face;
	t_vertex *selected_vertex;
	t_selection_mode selection_mode;
	sfTexture *selection_texture;
	sfSprite *selection_sprite;
	t_textbox *textbox;
	t_texture *brush;
	sfRectangleShape *brush_rect;
	int paint;
} t_game;

int init_game(t_game *);
t_game *create_game();
void update_game(t_game *);
void render_game(t_game *);
void destroy_game(t_game *);

sfRenderWindow *create_window(char *, unsigned int);
void update_state(t_game *, char *);
int check_env(char **);

#endif
