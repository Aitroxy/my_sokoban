/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** sokoban_struct_h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct box_s {
    int pos_x;
    int pos_y;
    int first_pos_x;
    int first_pos_y;
}box_t;

typedef struct charo_s {
    int pos_x;
    int pos_y;
}charo_t;

typedef struct sokoban_s {
    char **map;
    int pos_x;
    int pos_y;
    int first_pos_x;
    int first_pos_y;
    int nb_box;
    int choose_box;
    int choose_char;
    box_t *box;
    charo_t *char_o;
}sokoban_t;

#endif
