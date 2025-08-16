/*
** EPITECH PROJECT, 2022
** free_map
** File description:
** sokoban
*/

#include "include/my.h"
#include "include/struct.h"

void free_all(char **map, char *str)
{
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
    }
    free(map);
    free(str);
}

void free_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
    }
    free(map);
}

void free_struct(box_t *box, charo_t *char_o)
{
    free(box);
    free(char_o);
}
