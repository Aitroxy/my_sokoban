/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** sokoban_porject
*/

#include "include/my.h"
#include "include/struct.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <stdlib.h>
#include "include/my_strwa.h"

void loop_sokoban(int command, sokoban_t *move, char **new_map)
{
    display_map(move->map);
    mvprintw(move->pos_x, move->pos_y, "P");
    curs_set(0);
    refresh();
    command = getch();
    move_up_down(command, move);
    move_side(command, move);
    for (int choose_o = 0; choose_o < move->nb_box; choose_o++) {
        if (move->map[move->char_o[choose_o].pos_x]
                [move->char_o[choose_o].pos_y] == ' ')
            move->map[move->char_o[choose_o].pos_x]
            [move->char_o[choose_o].pos_y] = 'O';
    }
    if (command == 32) {
        free_map(move->map);
        move->map = my_arraydup(new_map);
        move->map = path_player(move);
    }
}

int sokoban(sokoban_t *move)
{
    int command = 0;
    char **new_map = my_arraydup(move->map);

    move->choose_char = 0;
    move->map = path_player(move);
    set_box(move);
    initscr();
    keypad(stdscr, TRUE);
    while (1) {
        loop_sokoban(command, move, new_map);
        if (check_win(move) == 0) {
            cond_win(move, new_map);
            return 0;
        }
        if (check_boxs_block(move) == move->nb_box)
            return (cond_win(move, new_map));
        clear();
    }
    free_map(new_map);
    return 1;
}

int main(int ac, char **av)
{
    (void)ac;
    sokoban_t move = {NULL};

    if (ac != 2)
        return 84;
    if (my_strncmp(av[1], "-h", 2) == 0) {
        usage();
        return 0;
    }
    if (error_map_pos(av[1], &move) == 84)
        return 84;
    if (sokoban(&move) == 0) {
        endwin();
        free_map(move.map);
        free_struct(move.box, move.char_o);
        return 0;
    }
    endwin();
    free_struct(move.box, move.char_o);
    return 1;
}
