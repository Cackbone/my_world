/*
** EPITECH PROJECT, 2018
** textbox.c
** File description:
** textbox
*/

#include <game.h>
#include <my_world.h>

t_textbox *create_textbox(char *desc, int max_size)
{
	t_textbox *box = malloc(sizeof(t_textbox));
	char *msg = malloc(sizeof(char) * (max_size + 1));
	sfRectangleShape *shape = sfRectangleShape_create();
	sfText *text = sfText_create();
	sfFont *font = sfFont_createFromFile("resources/fonts/prstart.ttf");
	sfText *descri = init_description(max_size, desc, font);

	if (!box || !msg || !shape || !text || !font || !descri)
		return (NULL);
	my_memset(msg, 0, max_size);
	init_textbox(shape, text, font, max_size);
	box->message = msg;
	box->text = text;
	box->font = font;
	box->shape = shape;
	box->index = 0;
	box->description = descri;
	box->max_size = max_size;
	return (box);
}

void add_char(t_textbox *box, char c)
{
	if (box->index + 1 < box->max_size) {
		box->message[box->index] = c;
		box->message[box->index + 1] = 0;
		box->index++;
		sfText_setString(box->text, box->message);
	}
}

void remove_char(t_textbox *box)
{
	if (box->index >= 0) {
		box->message[box->index] = 0;
		box->index--;
		sfText_setString(box->text, box->message);
	}
}

void update_textbox(t_game *game)
{
	t_textbox *box = game->textbox;
	int code = game->event->key.code;
	int shift = game->event->key.shift;
	char c = 0;

	if (!box)
		return;
	if (code >= sfKeyA && code <= sfKeyZ) {
		c = code - sfKeyA + 'a';
		if (shift)
			c += 'A' - 'a';
	}
	modify_textbox(game, code, c);
}

void destroy_textbox(t_textbox *box)
{
	sfText_destroy(box->text);
	sfRectangleShape_destroy(box->shape);
	free(box);
}
