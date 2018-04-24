/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** ah !
*/

#include <stdlib.h>
#include <macros.h>
#include <hashmap.h>

void put_helem(t_hashmap *hmap, char *key, void *value)
{
	t_hmap_node *node = malloc(sizeof(t_hmap_node));

	node->key = key;
	node->value = value;
	add_elem(hmap->list, node);
}

int get_hindex(t_hashmap *hmap, char *key)
{
	list_node_t *tmp = hmap->list->first;
	int index = 0;
	t_hmap_node *node = NULL;

	while (tmp != NULL) {
		node = tmp->data;
		if (EQUALS(node->key, key))
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

void *get_hmap(t_hashmap *hmap, char *key)
{
	int i = hmap->index(key);
	t_hmap_node *node = get_elem(hmap->list, i);

	return (node->value);
}

void rm_helem(t_hashmap *hmap, char *key)
{
	int i = hmap->index(key);

	if (i != -1)
		remove_elem(hmap->list, i);
}
