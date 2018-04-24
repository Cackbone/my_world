/*
** EPITECH PROJECT, 2018
** button.h
** File description:
** button
*/

#ifndef BUTTON_H_
#define BUTTON_H_

#include <my_world.h>

struct s_ui;
struct s_game;
struct s_button;

typedef void (*but_action)(struct s_game *, struct s_button *);

typedef struct s_button {
	sfRectangleShape *rect;
	sfTexture *idle;
	sfTexture *hover;
	sfTexture *click;
	int pressed;
	but_action action;
	sfText *text;
	int id;
} t_button;

t_button *create_button(sfVector2f *, char *, char **);
t_button **create_buttons(int);
void update_button(struct s_game *, t_button *);
void destroy_buttons(struct s_ui *);

sfRectangleShape *create_background_button(sfVector2f *, sfTexture **);
sfText *create_text(sfVector2f *, char *);

#endif
