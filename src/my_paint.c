/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** world
*/

#include <game.h>
#include <brush.h>

int init_brush(t_game *game)
{
	sfVector2f size = {100, 100};
	sfVector2f pos = {1800, 20};
	sfRectangleShape *rect = sfRectangleShape_create();

	if (!rect)
		return (0);
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setPosition(rect, pos);
	game->brush = NULL;
	game->brush_rect = rect;
	game->paint = 0;
	return (1);
}

int update_brush(t_game *game)
{
	sfIntRect iRect = {0, 0, 0, 0};
	t_hashmap *textures = game->map->textures;
	t_hmap_node *hnode = textures->list->first->data;
	t_texture *texture = hnode->value;
	sfRectangleShape *rect = game->brush_rect;

	if (!texture)
		return (84);
	iRect.left = texture->x;
	iRect.top = texture->y;
	iRect.width = texture->xsize;
	iRect.height = texture->ysize;
	game->brush = texture;
	sfRectangleShape_setTexture(rect, game->map->tilemap, sfFalse);
	sfRectangleShape_setTextureRect(rect, iRect);
	return (1);
}

void switch_brush(t_game *game)
{
	t_hashmap *texture = game->map->textures;
	list_node_t *tmp = NULL;
	t_hmap_node *node = NULL;

	if (!texture)
		return;
	tmp = texture->list->first;
	while (tmp) {
		node = tmp->data;
		if (!(my_strcmp(node->key, game->brush->name))) {
			update_texture(game, tmp);
			break;
		}
		tmp = tmp->next;
	}
}

void update_texture(t_game *game, list_node_t *tmp)
{
	t_hashmap *textures = game->map->textures;
	t_hmap_node *node = NULL;
	sfIntRect iRect = {0, 0, 0, 0};
	t_texture *texture = NULL;

	if (tmp->next)
		node = tmp->next->data;
	else
		node = textures->list->first->data;
	texture = node->value;
	game->brush = texture;
	iRect.left = texture->x;
	iRect.top = texture->y;
	iRect.width = texture->xsize;
	iRect.height = texture->ysize;
	sfRectangleShape_setTextureRect(game->brush_rect, iRect);
}

void display_brush(t_game *game)
{
	sfRenderWindow_drawRectangleShape(game->window, game->brush_rect, NULL);
}
