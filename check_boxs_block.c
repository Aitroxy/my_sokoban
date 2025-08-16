/*
** EPITECH PROJECT, 2022
** check_boxs_block
** File description:
** sokoban
*/

#include "my.h"

int cmp_char(char c, char *str)
{
    for (int i = 0; str[i]; i++) {
        if (c == str[i])
            return 0;
    }
    return 1;
}

int check_block(sokoban_t *move, int i, int j)
{
    int count_wall = 0;

    if (((cmp_char(move->map[i + 1][j], "#X") == 0) ||
        (cmp_char(move->map[i - 1][j], "#X") == 0)) &&
        ((cmp_char(move->map[i][j + 1], "#X") == 0) ||
        (cmp_char(move->map[i][j - 1], "#X") == 0)))
        count_wall++;
    return count_wall;
}

int loop_check_block(sokoban_t *move, int i, int count_block)
{
    for (int j = 0; move->map[i][j] != '\0'; j++) {
        if (move->map[i][j] == 'X')
            count_block += check_block(move, i, j);
    }
    return count_block;
}

int check_boxs_block(sokoban_t *move)
{
    int count_block = 0;

    for (int i = 0; move->map[i] != NULL; i++) {
        count_block = loop_check_block(move, i, count_block);
    }
    return (count_block);
}
