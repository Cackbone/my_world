/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** world
*/

#include <my_world.h>

int line_intersect(sfVector2f *v1, sfVector2f *v2, sfVector2f *pt)
{
	int valid1 = (v1->y <= pt->y) && (v2->y > pt->y);
	int valid2 = (v1->y > pt->y) && (v2->y <=  pt->y);
	float l1 = pt->x - v1->x;
	float l2 = pt->y - v1->y;
	float l3 = v2->y - v1->y;
	float l4 = v2->x - v1->x;

	if (valid1 || valid2)
		return (l1 < l2 / l3 * l4);
	return (0x0);
}

int vertex_contain(sfVector2f *p, sfVector2f *v)
{
	int side = line_intersect(v, v + 1, p);
	int side2 = line_intersect(v + 1, v + 2, p);
	int side3 = line_intersect(v + 2, v + 3, p);
	int side4 = line_intersect(v + 3, v + 0, p);

	return ((side + side2 + side3 + side4) & 0x1);
}

int face_contain(sfVector2f *m, t_face *f)
{
	sfFloatRect rect = sfVertexArray_getBounds(f->array);
	sfVector2f *p = get_face_projected(f);

	if (!p)
		return (0);
	if (m->x >= rect.left && m->x <= rect.left + rect.width) {
		if (m->y >= rect.top && m->y <= rect.top + rect.height)
			return (vertex_contain(m, p));
	}
	free(p);
	return (0);
}

sfVector2f *get_face_projected(t_face *face)
{
	sfVector2f *p = malloc(sizeof(sfVector2f) * 4);

	if (!p)
		return (NULL);
	for (int i = 0; i < 4; i++)
		p[i] = face->vertices[i]->projected;
	return (p);
}
