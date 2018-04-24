/*
** EPITECH PROJECT, 2018
** texture.h
** File description:
** texture
*/

#ifndef TEXTURE_H_
#define TEXTURE_H_

typedef struct s_texture {
	int x;
	int y;
	int xsize;
	int ysize;
	char *name;
} t_texture;

void destroy_texture(t_texture *);

#endif
