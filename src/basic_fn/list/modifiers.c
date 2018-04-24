/*
** EPITECH PROJECT, 2018
** modifiers.c
** File description:
** modifiers
*/

#include <stdlib.h>
#include <list/list.h>

int get_index(list_t *list, void *data)
{
	list_node_t *tmp = list->first;
	int index = 0;

	while (tmp != NULL) {
		if (tmp->data == data)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

void update_indices(list_t *list)
{
	list_node_t *tmp = list->first;
	int index = 0;

	while (tmp != NULL) {
		tmp->index = index;
		tmp = tmp->next;
		index++;
	}
}

void swap_nodes(list_t *list, int id1, int id2)
{
	list_node_t *node1 = get_node(list, id1);
	list_node_t *node2 = get_node(list, id2);
	void *tmp = NULL;

	tmp = node1->data;
	node1->data = node2->data;
	node2->data = tmp;
}

list_node_t *get_node(list_t *list, int index)
{
	list_node_t *tmp = list->first;

	while (tmp && (index > 0)) {
		tmp = tmp->next;
		index--;
	}
	return (tmp);
}
