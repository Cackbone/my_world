/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** shellsort
*/

#include <game.h>
#include <renderer.h>

int is_valid(list_t *list, int k, int i, sfVector3f *pos)
{
	t_face *k_face = get_elem(list, k);
	t_face *ki_face = get_elem(list, k + i);

	return (distance(ki_face, pos) >= distance(k_face, pos));
}

void check_sort(int i, int j, list_t *list, sfVector3f *pos)
{
	for (int k = j - i; k >= 0; k--) {
		if (is_valid(list, k, i, pos))
			break;
		else
			swap_nodes(list, k, k + i);
	}
}

list_t *shell_sort(list_t *list, sfVector3f *pos)
{
	int n = list->size;

	for (int i = n / 2; i > 0; i /= 2)
		for (int j = i; j < n; j++)
			check_sort(i, j, list, pos);
	return (list);
}
