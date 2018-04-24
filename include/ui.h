/*
** EPITECH PROJECT, 2018
** ui.h
** File description:
** ui
*/

#ifndef UI_H_
#define UI_H_

#include <button.h>
#include <my_world.h>

#define BUTTONS	6

typedef struct s_ui {
	int ui_pause;
	sfRectangleShape *side_panel;
	t_button **buttons;
	int nb_buttons;
	sfSprite *background;
	sfText *state_text;
} t_ui;

sfRectangleShape *create_side_panel();
sfSprite *create_background();
t_ui *create_ui();
void destroy_ui(t_ui *);
char **ui_open(void);

#endif
