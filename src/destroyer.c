/*
** EPITECH PROJECT, 2018
** destroyer.c
** File description:
** destroyer
*/

#include <map.h>
#include <my_world.h>

void destroy_faces(list_t *faces)
{
	list_node_t *node = faces->first;
	list_node_t *tmp = NULL;
	t_face *face = NULL;

	while (node) {
		tmp = node->next;
		face = node->data;
		if (face->array)
			sfVertexArray_destroy(face->array);
		free(face->vertices);
		free(face);
		free(node);
		node = tmp;
	}
	free(faces);
}

void destroy_map(t_map *map)
{
	t_hashmap *hmap = map->textures;

	destroy_faces(map->faces);
	delete_list(map->vertices);
	hmap->delete();
	if (map->tilemap)
		sfTexture_destroy(map->tilemap);
	if (map->tilemap_filepath)
		free(map->tilemap_filepath);
	free(map->states);
	free(map);
}
