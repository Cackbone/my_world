/*
** EPITECH PROJECT, 2018
** parser.h
** File description:
** parser
*/

#ifndef PARSER_H_
#define PARSER_H_

#include <map.h>
#include <my_world.h>

typedef int (*parser_func)(t_map *, char **, int);

typedef struct s_parser {
	char *name;
	parser_func func;
} t_parser;

int load_texture(t_map *, char **, int);
int create_vertex(t_map *, char **, int);
int create_texture(t_map *, char **, int);
int parse_rotation(char **);
int create_face(t_map *, char **, int);

#define PARSER_COUNT	4
const t_parser PARSERS[4] = {
	{ "tm", load_texture },
	{ "v", create_vertex },
	{ "t", create_texture },
	{ "f", create_face }
};

#endif
