/*
** EPITECH PROJECT, 2018
** textbox_modifier.c
** File description:
** textbox_modifier
*/

#include <game.h>

void init_textbox(sfRectangleShape *shape, sfText *text, sfFont *font, int ms)
{
	sfVector2f text_pos = {0, 0};
	sfVector2f rsize = {0, 50};

	rsize.x = 30 * ms;
	text_pos.x = (1920 - 12 * ms) / 2 - 6;
	text_pos.y = (1080 - 12) / 2 - 6;
	sfRectangleShape_setFillColor(shape, sfWhite);
	sfRectangleShape_setPosition(shape, text_pos);
	sfRectangleShape_setSize(shape, rsize);
	sfText_setCharacterSize(text, 28);
	sfText_setFont(text, font);
	sfText_setString(text, "");
	sfText_setColor(text, sfBlack);
	text_pos.x += 6;
	text_pos.y += 6;
	sfText_setPosition(text, text_pos);
}

void modify_textbox(t_game *game, int code, char c)
{
	t_textbox *box = game->textbox;

	switch (code) {
	case sfKeySpace:
		c = '_';
		break;
	case sfKeyReturn:
		if (my_strlen(box->message) > 0)
			box->on_enter(game, box->message);
		break;
	case sfKeyBack:
		remove_char(box);
		break;
	}
	if (c)
		add_char(box, c);
}

void render_textbox(t_game *game)
{
	t_ui *ui = game->ui;
	sfRenderWindow *win = game->window;
	sfVector2f size = sfRectangleShape_getSize(ui->side_panel);
	t_textbox *box = game->textbox;

	if (box && size.x >= 1920) {
		sfRenderWindow_drawRectangleShape(win, box->shape, NULL);
		sfRenderWindow_drawText(win, box->text, NULL);
		sfRenderWindow_drawText(win, box->description, NULL);
	}
}

sfText *init_description(int ms, char *desc, sfFont *font)
{
	sfText *text = sfText_create();
	sfVector2f pos = {0, 0};

	if (!font || !text)
		return (NULL);
	pos.x = (1920 - 12 * ms) / 2;
	pos.y = (1080 - 12) / 2 - 100;
	sfText_setFont(text, font);
	sfText_setString(text, desc);
	sfText_setColor(text, sfWhite);
	sfText_setPosition(text, pos);
	sfText_setCharacterSize(text, 34);
	return (text);
}
