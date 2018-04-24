/*
** EPITECH PROJECT, 2018
** textbox.h
** File description:
** textbox
*/

#ifndef TEXTBOX_H_
#define TEXTBOX_H_

typedef struct s_textbox {
	char *message;
	sfText *description;
	int index;
	int max_size;
	sfText *text;
	sfFont *font;
	sfRectangleShape *shape;
	void (*on_enter)(t_game *, char *);
	void (*on_quit)(t_game *);
} t_textbox;

void init_textbox(sfRectangleShape *, sfText *, sfFont *, int);
void modify_textbox(t_game *, int, char);
void render_textbox(t_game *);
sfText *init_description(int, char *, sfFont *);

t_textbox *create_textbox(char *, int);
void add_char(t_textbox *, char);
void remove_char(t_textbox *);
void update_textbox(t_game *);
void destroy_textbox(t_textbox *);

#endif
