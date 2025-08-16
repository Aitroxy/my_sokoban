/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** handle_box
*/

#include "include/my.h"
#include "include/struct.h"
#include <unistd.h>

int loop_count_object(char **map, int count_box, int i, char c)
{
    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] == c)
            count_box++;
        if (map[i][j] != ' ' && map[i][j] != 'X' && map[i][j] != 'O' &&
            map[i][j] != '#' && map[i][j] != '\n' && map[i][j] != 'P')
            return -1;
    }
    return count_box;
}

int count_object(char **map, char c)
{
    int count_box = 0;

    for (int i = 0; map[i] != NULL; i++) {
        count_box = loop_count_object(map, count_box, i, c);
    }
    return count_box;
}

void init_map(sokoban_t *move, char *file)
{
    move->map = my_str_to_array(file, '\n');
    move->nb_box = count_object(move->map, 'X');
}

int error_map_pos(char *arg, sokoban_t *move)
{
    char *file = NULL;
    int count_place = 0;

    file = get_file(arg);
    if (file == NULL) {
        free(file);
        return 84;
    }
    init_map(move, file);
    count_place = count_object(move->map, 'O');
    if (move->nb_box != count_place) {
        free_all(move->map, file);
        return 84;
    }
    if (count_object(move->map, 'P') != 1) {
        free_all(move->map, file);
        return 84;
    }
    free(file);
    return 0;
}
