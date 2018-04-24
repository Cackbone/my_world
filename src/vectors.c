/*
** EPITECH PROJECT, 2018
** vectors.c
** File description:
** vectors
*/

#include <my_world.h>

sfVector3f *create_vector3(float x, float y, float z)
{
	sfVector3f *vec = malloc(sizeof(sfVector3f));

	if (!vec)
		return (NULL);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

sfVector2f *create_vector2(float x, float y)
{
	sfVector2f *vec = malloc(sizeof(sfVector2f));

	if (!vec)
		return (NULL);
	vec->x = x;
	vec->y = y;
	return (vec);
}

sfFloatRect createFloatRect(float x1, float y1, float x2, float y2)
{
	sfFloatRect rect = {0, 0, 0, 0};

	rect.left = x1;
	rect.top = y1;
	rect.width = x2;
	rect.height = y2;
	return (rect);
}
