/*
** EPITECH PROJECT, 2018
** map.h
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include <my_world.h>

struct s_game;

typedef struct s_vertex {
	float x;
	float y;
	float z;
	int id;
	sfVector2f projected;
} t_vertex;

typedef struct s_face {
	t_vertex **vertices;
	t_texture *texture;
	int rotation;
	sfVertexArray *array;
	sfVertexArray *grid;
	sfColor color;
} t_face;

typedef struct s_map {
	list_t *vertices;
	list_t *faces;
	list_t *render_faces;
	char *filepath;
	t_hashmap *textures;
	sfTexture *tilemap;
	char *tilemap_filepath;
	sfRenderStates *states;
	int x_size;
	int y_size;
	int z_size;
} t_map;

t_map *create_map(char *);
int parse_line(t_map *, char *);
int load_file(t_map *, FILE *);
t_map *load_map(char *, struct s_game *);

sfVector2f rotate_texture(t_face *, sfVector2f *);
sfVector2f project_point(t_vertex *, struct s_game *);
void create_quad(t_face *);
void create_lines(t_face *);
void update_vertex_array(struct s_game *);

void init_face(t_face *, t_vertex **, t_texture *);
void my_selection(struct s_game *, float);
void render_face(struct s_game *, t_face *);
void render_map(struct s_game *);

int get_vertex_id(t_map *, t_face *, int);
void save_vertices(int, t_map *);
void save_textures(int, t_map *);
void save_faces(int, t_map *);
void save_map(struct s_game *, char *);

void destroy_faces(list_t *);
void destroy_map(t_map *);

#endif
