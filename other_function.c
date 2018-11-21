/*
** EPITECH PROJECT, 2018
** i need
** File description:
** space
*/

#include "my.h"

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
