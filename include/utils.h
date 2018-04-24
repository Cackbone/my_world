/*
** EPITECH PROJECT, 2018
** utils.h
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

#include <map.h>

struct s_map;
struct s_vertex;

int get_value(char *);
char *clear_line(char *);
void check_map_limit(struct s_map *, struct s_vertex *);

#endif
