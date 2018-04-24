/*
** EPITECH PROJECT, 2018
** list.h
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

typedef struct list_node_s {
	void *data;
	int index;
	struct list_node_s *next;
} list_node_t;

typedef struct list_s {
	list_node_t *first;
	list_node_t *last;
	int size;
} list_t;

list_t *create_list();
void add_elem(list_t *, void *);
list_node_t *get_node(list_t *, int);
void *get_elem(list_t *, int);
int get_index(list_t *, void *);
void remove_elem(list_t *, int);
void swap_nodes(list_t *, int, int);
void delete_list(list_t *);
void update_indices(list_t *);

#endif
