/*
** EPITECH PROJECT, 2018
** i need
** File description:
** line
*/

#include "my.h"
#include <unistd.h>

int get_line(char *str)
{
    int j = 0;
    int k = 0;

    while (str[j] != '\n') {
        if (str[j] >= '0' && str[j] <= '9')
            k = k * 10 + str[j] - '0';
        j = j + 1;
    }
    return (k);
}

int get_cols(char *str)
{
    int j = 0;
    int k = 0;
    int h = 0;

    while (str[h] != '\n')
        h = h + 1;
    h = h + 1;
    while (k < 2) {
        if (str[j] == '\n')
            k = k + 1;
        j = j + 1;
    }
    j = j - h;
    return (j);
}
