/*
** EPITECH PROJECT, 2022
** check_win
** File description:
** sokoban
*/

#include "my.h"

int loop_check_win(sokoban_t *move, int i)
{
    for (int j = 0; move->map[i][j] != '\0'; j++) {
        if (move->map[i][j] == 'O')
            return 1;
    }
    return 0;
}

int check_win(sokoban_t *move)
{
    for (int i = 0; move->map[i] != NULL; i++) {
        if (loop_check_win(move, i) == 1)
            return 1;
    }
    return 0;
}

int cond_win(sokoban_t *move, char **new_map)
{
    free_map(new_map);
    clear();
    display_map(move->map);
    mvprintw(move->pos_x, move->pos_y, "P");
    refresh();
    return 1;
}
