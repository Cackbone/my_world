/*
** EPITECH PROJECT, 2018
** button.c
** File description:
** button
*/

#include <unistd.h>
#include <game.h>
#include <my_world.h>
#include <button_defs.h>

t_button *create_button(sfVector2f *data, char *text, char **textures)
{
	t_button *button = malloc(sizeof(t_button));
	sfTexture **texs = malloc(sizeof(sfTexture *) * 3);
	sfIntRect tex_rect = {0, 0, 300, 100};
	sfText *txt = create_text(data, text);
	sfRectangleShape *rect = NULL;

	for (int i = 0; texs && i < 3; i++)
		texs[i] = sfTexture_createFromFile(textures[i], &tex_rect);
	rect = create_background_button(data, texs);
	if (!button || !txt || !texs || !rect)
		return (NULL);
	button->rect = rect;
	button->pressed = 0;
	button->action = NULL;
	button->idle = texs[0];
	button->hover = texs[1];
	button->click = texs[2];
	button->text = txt;
	return (button);
}

t_button **create_buttons(int nb_buttons)
{
	t_button **buttons = malloc(sizeof(t_button *) * nb_buttons);
	sfVector2f *data = malloc(sizeof(sfVector2f) * 2);
	char *texts[7] = {"Load", "Save", "Textures", "Reset", "Pause", "Quit"};
	char *textures[3] = {
		"resources/img/buttons/button_idle.png",
		"resources/img/buttons/button_hover.png",
		"resources/img/buttons/button_click.png"
	};

	for (int i = 0; i < nb_buttons; i++) {
		data[0].x = X_POSITIONS[i];
		data[0].y = Y_POSITIONS[i];
		data[1].x = X_SIZES[i];
		data[1].y = Y_SIZES[i];
		buttons[i] = create_button(data, texts[i], textures);
		if (!buttons[i])
			return (NULL);
		buttons[i]->id = i;
		buttons[i]->action = ACTIONS[i];
	}
	free(data);
	return (buttons);
}

void update_button(t_game *game, t_button *b)
{
	sfVector2f size = sfRectangleShape_getSize(b->rect);
	sfVector2f pos = sfRectangleShape_getPosition(b->rect);
	sfVector2i mouse = sfMouse_getPosition(NULL);
	int x = ((mouse.x >= pos.x) && (mouse.x <= (pos.x + size.x)));
	int y = ((mouse.y >= pos.y) && (mouse.y <= (pos.y + size.y)));

	if (x && y) {
		if (sfMouse_isButtonPressed(sfMouseLeft)) {
			sfRectangleShape_setTexture(b->rect, b->click, sfFalse);
			if (!b->pressed && b->action) {
				b->pressed = 1;
				b->action(game, b);
			}
		} else {
			sfRectangleShape_setTexture(b->rect, b->hover, sfFalse);
			b->pressed = 0;
		}
	} else {
		sfRectangleShape_setTexture(b->rect, b->idle, sfFalse);
		b->pressed = 0;
	}
}

void destroy_buttons(t_ui *ui)
{
	t_button *but = NULL;
	sfFont *tmp = NULL;

	for (int i = 0; i < ui->nb_buttons; i++) {
		but = ui->buttons[i];
		sfRectangleShape_destroy(but->rect);
		sfTexture_destroy(but->idle);
		sfTexture_destroy(but->hover);
		sfTexture_destroy(but->click);
		tmp = (sfFont *) sfText_getFont(but->text);
		sfFont_destroy(tmp);
		sfText_destroy(but->text);
		free(but);
	}
	free(ui->buttons);
}
