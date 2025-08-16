/*
** EPITECH PROJECT, 2022
** handle_box
** File description:
** sokoban
*/

#include "include/my.h"
#include "include/struct.h"

void loop_set_box(sokoban_t *move, int i)
{
    for (int j = 0; move->map[i][j] != '\0'; j++) {
        if (move->map[i][j] == 'X') {
            move->box[move->choose_box].pos_x = i;
            move->box[move->choose_box].pos_y = j;
            move->choose_box++;
        }
        if (move->map[i][j] == 'O') {
            move->char_o[move->choose_char].pos_x = i;
            move->char_o[move->choose_char].pos_y = j;
            move->choose_char++;
        }
    }
}

void set_box(sokoban_t *move)
{
    move->box = malloc(sizeof(box_t) * (move->nb_box + 1));
    move->char_o = malloc(sizeof(charo_t) * (move->nb_box + 1));
    for (int i = 0; move->map[i] != NULL; i++) {
        loop_set_box(move, i);
    }
}
