/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** hashmap
*/

#include <stdlib.h>
#include <hashmap.h>

t_hashmap *create_hashmap(void)
{
	t_hashmap *hmap = malloc(sizeof(t_hashmap));
	list_t *list = create_list();

	if (!hmap || !list)
		return (NULL);
	hmap->list = list;
	hmap->add = put_helem;
	hmap->get = get_hmap;
	hmap->get_index = get_hindex;
	hmap->remove = rm_helem;
	hmap->delete = delete_hashmap;
	return (hmap);
}

void delete_hashmap(t_hashmap *hmap)
{
	list_node_t *tmp = NULL;
	list_node_t *node = hmap->list->first;
	t_hmap_node *hnode = NULL;

	while (node) {
		tmp = node->next;
		hnode = node->data;
		free(hnode->key);
		free(hnode->value);
		free(hnode);
		free(node);
		node = tmp;
	}
	free(hmap->list);
	free(hmap);
}
