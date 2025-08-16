/*
** EPITECH PROJECT, 2021
** B-MUL-100-RUN-1-1-myrunner-guillyann.ferrere
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include "struct.h"
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <ncurses.h>
    #include <stdlib.h>

int my_strcmp(char const *s1, char const *s2);
int my_strcmp_equal(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_memset(char *str, int size);
char *my_strcpy(char *dest, char const *src, char c);
char *my_strdup(char *src, char c);
int my_strlen(char *str, char c);
char **my_str_to_array(char *str, char c);
int count_object(char **map, char c);
void usage(void);
int error_map_pos(char *arg, sokoban_t *move);
char *get_file(char *arg);
char **path_player(sokoban_t *move);
void display_map(char **map);
void set_box(sokoban_t *move);
void move_up_down(int command, sokoban_t *move);
void move_side(int command, sokoban_t *move);
void free_all(char **map, char *str);
void free_struct(box_t *box, charo_t *char_o);
void free_map(char **map);
char **my_arraydup(char **env);
int array_len(char **array);
int check_win(sokoban_t *move);
int loop_check_win(sokoban_t *move, int i);
int cond_win(sokoban_t *move, char **new_map);
int check_boxs_block(sokoban_t *move);

#endif
