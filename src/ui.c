/*
** EPITECH PROJECT, 2018
** ui.c
** File description:
** ui
*/

#include <ui.h>

sfRectangleShape *create_side_panel(void)
{
	sfRectangleShape *side_panel = sfRectangleShape_create();
	sfVector2f panel_data[2] = {{0, 0}, {500, 1080}};
	sfColor transparent = {10, 10, 10, 90};

	if (!side_panel)
		return (NULL);
	sfRectangleShape_setPosition(side_panel, panel_data[0]);
	sfRectangleShape_setSize(side_panel, panel_data[1]);
	sfRectangleShape_setFillColor(side_panel, transparent);
	return (side_panel);
}

sfSprite *create_background(void)
{
	sfSprite *background = sfSprite_create();
	sfTexture *bg = sfTexture_createFromFile("resources/img/bg.png", NULL);
	sfVector2f pos = {0, 0};

	if (!background || !bg)
		return (NULL);
	sfSprite_setTexture(background, bg, sfFalse);
	sfSprite_setPosition(background, pos);
	return (background);
}

t_ui *create_ui(void)
{
	t_ui *ui = malloc(sizeof(t_ui));
	sfText *state_text = sfText_create();
	sfFont *font = sfFont_createFromFile("resources/fonts/prstart.ttf");
	sfVector2f txt_pos = {1000, 950};
	sfRectangleShape *side_panel = create_side_panel();
	sfSprite *background = create_background();

	if (!ui || !font || !state_text || !side_panel || !background)
		return (NULL);
	ui->buttons = create_buttons(BUTTONS);
	ui->nb_buttons = BUTTONS;
	sfText_setString(state_text, "");
	sfText_setPosition(state_text, txt_pos);
	sfText_setColor(state_text, sfRed);
	sfText_setFont(state_text, font);
	ui->state_text = state_text;
	ui->side_panel = side_panel;
	ui->background = background;
	ui->ui_pause = 0;
	return (ui);
}

void destroy_ui(t_ui *ui)
{
	sfTexture *tex = (sfTexture *) sfSprite_getTexture(ui->background);

	destroy_buttons(ui);
	sfRectangleShape_destroy(ui->side_panel);
	sfTexture_destroy(tex);
	sfSprite_destroy(ui->background);
	sfText_destroy(ui->state_text);
	free(ui);
}
