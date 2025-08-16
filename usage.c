/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** description_sokoban
*/

#include "include/my.h"
#include <unistd.h>

void usage(void)
{
    write(1, "USAGE\n      ./my_sokoban map\nDESCRIPTION\n      map file", 56);
    write(1, " representing the warehouse map, containing '#' for ", 53);
    write(1, "walls,\n          'P' for the player, 'X' for boxes", 51);
    write(1, " and '0' for storage locations.", 32);
}
