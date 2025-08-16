/*
** EPITECH PROJECT, 2022
** memset
** File description:
** replace_char_into_zero
*/

#include "include/my.h"

char *my_memset(char *str, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return (str);
}
