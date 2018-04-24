/*
** EPITECH PROJECT, 2018
** rotate_texture.c
** File description:
** rotate_texture
*/

#include <math.h>
#include <my_world.h>

sfVector2f rotate_texture(t_face *f, sfVector2f *p)
{
	t_texture *tex = f->texture;
	sfTransform trans = sfTransform_Identity;
	float midX = tex->x + tex->xsize / 2.0;
	float midY = tex->y + tex->ysize / 2.0;
	float rot = (float)f->rotation * 90.0;
	sfVector2f res = {0, 0};

	sfTransform_rotateWithCenter(&trans, rot, midX, midY);
	res = sfTransform_transformPoint(&trans, *p);
	return (res);
}
