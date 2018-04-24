/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** game
*/

#include <game.h>
#include <brush.h>
#include <game_def.h>

int init_game(t_game *game)
{
	sfTexture *texture = sfTexture_createFromFile(SELECTION_PATH, NULL);
	sfSprite *sprite = sfSprite_create();

	if (!texture || !sprite)
		return (1);
	sfSprite_setTexture(sprite, texture, sfTrue);
	game->selected_vertex = NULL;
	game->selected_face = NULL;
	game->selection_mode = FACE;
	game->translate = NULL;
	game->scale = NULL;
	game->textbox = NULL;
	game->skybox = sfColor_fromRGB(144, 244, 247);
	game->running = 1;
	game->playing = 1;
	game->selection_texture = texture;
	game->selection_sprite = sprite;
	init_brush(game);
	return (0);
}

t_game *create_game(void)
{
	t_game *game = malloc(sizeof(t_game));
	sfRenderWindow *win = create_window("My World", 60);
	sfEvent *event = malloc(sizeof(sfEvent));
	sfView *view = sfView_create();
	sfVector2f *angle = create_vector2(TO_RAD(35), TO_RAD(45));
	t_ui *ui = create_ui();
	player_t *player = create_player();

	if (!game || !win || !event || !angle || !ui || !player)
		return (NULL);
	game->ui = ui;
	game->window = win;
	game->event = event;
	game->angle = angle;
	game->player = player;
	game->view = view;
	sfView_setViewport(view, createFloatRect(VIEW_X1, 0, VIEW_X2, 1));
	if (init_game(game))
		return (NULL);
	return (game);
}

void update_game(t_game *game)
{
	t_ui *ui = game->ui;
	sfColor clr;
	sfVector2f size = sfRectangleShape_getSize(ui->side_panel);

	if (ui->ui_pause && size.x <= 1920) {
		size.x += 30;
		sfRectangleShape_setSize(ui->side_panel, size);
	} else if (!(ui->ui_pause) && size.x > 500) {
		size.x -= 30;
		sfRectangleShape_setSize(ui->side_panel, size);
	}
	clr = sfText_getColor(ui->state_text);
	clr.a -= (clr.a > 1 ? 2 : 0);
	sfText_setColor(ui->state_text, clr);
	if (game->textbox)
		return;
	for (int i = 0; i < ui->nb_buttons; i++)
		update_button(game, ui->buttons[i]);
}

void render_game(t_game *game)
{
	t_ui *ui = game->ui;
	sfRenderWindow *win = game->window;
	t_button *but = NULL;

	sfRenderWindow_drawSprite(win, ui->background, NULL);
	sfRenderWindow_setView(win, game->view);
	if (game->map)
		render_map(game);
	sfRenderWindow_setView(win, sfRenderWindow_getDefaultView(win));
	if (game->paint)
		display_brush(game);
	sfRenderWindow_drawRectangleShape(win, ui->side_panel, NULL);
	for (int i = 0; i < ui->nb_buttons; i++) {
		but = ui->buttons[i];
		sfRenderWindow_drawRectangleShape(win, but->rect, NULL);
		sfRenderWindow_drawText(win, but->text, NULL);
	}
	sfRenderWindow_drawText(win, ui->state_text, NULL);
	render_textbox(game);
}

void destroy_game(t_game *game)
{
	if (game->map) {
		destroy_map(game->map);
		free(game->scale);
		free(game->translate);
	}
	free(game->angle);
	if (game->view)
		sfView_destroy(game->view);
	if (game->textbox)
		destroy_textbox(game->textbox);
	sfRenderWindow_close(game->window);
	sfRenderWindow_destroy(game->window);
	destroy_player(game->player);
	free(game->event);
	free(game);
}
