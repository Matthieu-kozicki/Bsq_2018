/*
** EPITECH PROJECT, 2018
** i need
** File description:
** line
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

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

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int i = 0;
    char **result = malloc(sizeof(char *) * (nb_rows + 2));

    result[nb_rows + 1] = NULL;
    for (i = 0; i <= nb_rows; i++) {
        result[i] = malloc(sizeof(char) * (nb_cols + 2));
        result[i][nb_rows + 1] = '\0';
    }
    return (result);
}

void free_2d(char **str, int nb_rows, int nb_cols)
{
    int i = 0;

    for (i = 0; i <= nb_rows; i++)
        free(str[i]);
    free(str);
}

char **load_2d_arr_from_file(char *str, int nb_rows, int nb_cols)
{
    int hight = 0;
    int lon = 1;
    char **copy = mem_alloc_2d_array(nb_rows, nb_cols);
    int k = 0;

    while (hight < nb_rows) {
        while (str[k] != '\n') {
            if (str[k] == '.')
                copy[hight][lon] = 1 + '0';
            else copy[hight][lon] = str[k];
            lon = lon + 1;
            k = k + 1;
        }
        copy[hight][lon] = '\n';
        lon = 0;
        hight = hight + 1;
        k = k + 1;
    }
    return (copy);
}
