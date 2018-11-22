/*
** EPITECH PROJECT, 2018
** i need
** File description:
** space
*/

#include "my.h"

int main(int arc, char **arg)
{
    if (arc != 2) {
        my_putstr("Error");
        return (84);
    }
    if (arg[1][0] == '-' && arg[1][1] == 'h') {
        my_putstr("USAGE\n   ./bsq map\n");
        my_putstr("DESCRIPTION\n   map");
        my_putstr(" with number of line at the first line\n");
        my_putstr("   '.' representing an empty place");
        my_putstr(" and 'o' representing an obstacle\n");
        return (84);
    }
    the_bsq(arc, arg);
}

char bsq(char x, char y, char z)
{
    char n = 0;

    if (x == 'o' || y == 'o' || z == 'o') {
        n = '1';
        return (n);
    }
    if (x <= y && x <= z)
        n = x + 1;
    if (y <= x && y <= z)
        n = y + 1;
    if (z <= x && z <= y)
        n = z + 1;
    return (n);
}

char **show_square(char **str, int rows, int cols)
{
    int hight = 1;
    int lon = 1;
    int k = 0;

    while (hight < rows) {
        while (str[hight][k] != '\n') {
            if (str[hight][k] != 'o' && str[hight][k] != 'x')
                str[hight][k] = '.';
            k = k + 1;
        }
        my_putstr(str[hight]);
        k = 0;
        hight = hight + 1;
    }
}
