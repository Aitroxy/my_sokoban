/*
** EPITECH PROJECT, 2022
** move
** File description:
** all_move
*/

#include "include/struct.h"
#include "include/my.h"

void cond_up_down(sokoban_t *move, char check, int operator)
{
    if (move->map[move->pos_x + (operator * 2)][move->pos_y] == check) {
        move->map[move->pos_x + operator][move->pos_y] = ' ';
        move->map[move->pos_x + (operator * 2)][move->pos_y] = 'X';
    }
}

void cond_side(sokoban_t *move, char check, int operator)
{
    if (move->map[move->pos_x][move->pos_y + (operator * 2)] == check) {
        move->map[move->pos_x][move->pos_y + operator] = ' ';
        move->map[move->pos_x][move->pos_y + (operator * 2)] = 'X';
    }
}

void move_up_down(int command, sokoban_t *move)
{
    if (command == KEY_UP) {
        if (move->map[move->pos_x - 1][move->pos_y] == 'X') {
            cond_up_down(move, ' ', - 1);
            cond_up_down(move, 'O', - 1);
        }
        if (move->map[move->pos_x - 1][move->pos_y] != '#' &&
            move->map[move->pos_x - 1][move->pos_y] != 'X')
            move->pos_x--;
    }
    if (command == KEY_DOWN) {
        if (move->map[move->pos_x + 1][move->pos_y] == 'X') {
            cond_up_down(move, ' ', 1);
            cond_up_down(move, 'O', 1);
        }
        if (move->map[move->pos_x + 1][move->pos_y] != '#' &&
            move->map[move->pos_x + 1][move->pos_y] != 'X')
            move->pos_x++;
    }
}

void move_side(int command, sokoban_t *move)
{
    if (command == KEY_LEFT) {
        if (move->map[move->pos_x][move->pos_y - 1] == 'X') {
            cond_side(move, ' ', - 1);
            cond_side(move, 'O', - 1);
        }
        if (move->map[move->pos_x][move->pos_y - 1] != '#' &&
            move->map[move->pos_x][move->pos_y - 1] != 'X')
            move->pos_y--;
    }
    if (command == KEY_RIGHT) {
        if (move->map[move->pos_x][move->pos_y + 1] == 'X') {
            cond_side(move, ' ', 1);
            cond_side(move, 'O', 1);
        }
        if (move->map[move->pos_x][move->pos_y + 1] != '#' &&
            move->map[move->pos_x][move->pos_y + 1] != 'X')
            move->pos_y++;
    }
}
