/*
** EPITECH PROJECT, 2018
** list.c
** File description:
** list
*/

#include <my.h>
#include <stdlib.h>
#include <list/list.h>

list_t *create_list(void)
{
	list_t *list = malloc(sizeof(list_t));

	if (list) {
		list->first = NULL;
		list->last = NULL;
		list->size = 0;
	}
	return (list);
}

void add_elem(list_t *list, void *data)
{
	list_node_t *node = malloc(sizeof(list_node_t));

	if (node) {
		node->data = data;
		node->next = NULL;
		node->index = list->size;
		if (list->first == NULL)
			list->first = node;
		else
			list->last->next = node;
		list->last = node;
		list->size++;
	}
}

void *get_elem(list_t *list, int index)
{
	list_node_t *node = get_node(list, index);

	return (node ? node->data : NULL);
}

void remove_elem(list_t *list, int index)
{
	list_node_t *prev = NULL;
	list_node_t *tmp = list->first;

	while ((tmp != NULL) && (index > 0)) {
		prev = tmp;
		tmp = tmp->next;
		index--;
	}
	if (tmp != NULL) {
		list->size--;
		if (prev != NULL)
			prev->next = tmp->next;
		if (list->first == tmp)
			list->first = tmp->next;
		if (list->last == tmp)
			list->last = prev;
		free(tmp);
		update_indices(list);
	}
}

void delete_list(list_t *list)
{
	list_node_t *tmp = NULL;
	list_node_t *node = list->first;

	while (node != NULL) {
		tmp = node->next;
		free(node->data);
		free(node);
		node = tmp;
	}
	free(list);
}
