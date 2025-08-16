/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** map_handle_sokoban
*/

#include "include/my.h"

char *get_file(char *arg)
{
    struct stat size;
    int fd = 0;
    char *buff = NULL;

    stat(arg, &size);
    if ((fd = open(arg, O_RDONLY)) == -1)
        return NULL;
    buff = malloc(sizeof(char) * (size.st_size + 1));
    if (read(fd, buff, size.st_size) == -1)
        return NULL;
    buff[size.st_size] = '\0';
    close(fd);
    return buff;
}

void loop_path_player(sokoban_t *move, int i, int j)
{
    for (j = 0; move->map[i][j] != '\0'; j++) {
        if (move->map[i][j] == 'P') {
            move->pos_x = i;
            move->pos_y = j;
            move->map[i][j] = ' ';
        }
    }
}

char **path_player(sokoban_t *move)
{
    int i = 0;
    int j = 0;

    for (; move->map[i] != NULL; i++)
        loop_path_player(move, i, j);
    move->first_pos_x = move->pos_x;
    move->first_pos_y = move->pos_y;
    return move->map;
}

void display_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        printw("%s\n", map[i]);
}
