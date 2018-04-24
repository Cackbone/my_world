/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** ah!
*/

#ifndef HASHMAP_H_
#define HASHMAP_H_

#define add(key, value) add(hmap, key, value)
#define get(key) get(hmap, key)
#define index(key) get_index(hmap, key)
#define rm(key) remove(hmap, key)
#define delete() delete(hmap)

#include <list/list.h>

typedef struct s_hmap_node {
	char *key;
	void *value;
} t_hmap_node;

typedef struct s_hashmap {
	list_t *list;
	void (*add)(struct s_hashmap *, char *, void *);
	void *(*get)(struct s_hashmap *, char *);
	int (*get_index)(struct s_hashmap *, char *);
	void (*remove)(struct s_hashmap *, char *);
	void (*delete)(struct s_hashmap *);
} t_hashmap;

t_hashmap *create_hashmap();
void put_helem(t_hashmap *, char *, void *);
void *get_hmap(t_hashmap *, char *);
int get_hindex(t_hashmap *, char *);
void rm_helem(t_hashmap *, char *);
void delete_hashmap(t_hashmap *);

#endif
