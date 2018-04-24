/*
** EPITECH PROJECT, 2018
** button_utils.c
** File description:
** button_utils
*/

#include <my_world.h>

sfRectangleShape *create_background_button(sfVector2f *data, sfTexture **texs)
{
	sfRectangleShape *shape = sfRectangleShape_create();

	if (!shape)
		return (NULL);
	sfRectangleShape_setPosition(shape, data[0]);
	sfRectangleShape_setSize(shape, data[1]);
	sfRectangleShape_setTexture(shape, texs[0], sfFalse);
	return (shape);
}

sfText *create_text(sfVector2f *data, char *text)
{
	sfText *txt = sfText_create();
	sfFont *font = sfFont_createFromFile("resources/fonts/prstart.ttf");
	sfVector2f pos = data[0];
	sfVector2f size = data[1];
	sfVector2f text_pos = {0, 0};

	text_pos.x = pos.x + (size.x / 2) - (my_strlen(text) * 13);
	text_pos.y = pos.y + (size.y / 2) - 20;
	if (!txt)
		return (NULL);
	sfText_setString(txt, text);
	sfText_setColor(txt, sfBlack);
	sfText_setFont(txt, font);
	sfText_setPosition(txt, text_pos);
	return (txt);
}
