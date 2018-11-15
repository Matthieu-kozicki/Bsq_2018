/*
** EPITECH PROJECT, 2018
** find the bigest
** File description:
** square ;T
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include <stdio.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int i;
    char **result = malloc(sizeof(char *) * nb_cols + 2);


    for (i = 0; i <= nb_rows; i++) {
        result[i] = malloc(sizeof(char *) * nb_rows + 2);
    }
    return (result);
}

int **int_alloc_2d_array(int nb_rows, int nb_cols)
{
    int i;
    int **result = malloc(sizeof(int *) * nb_cols + 2);


    for (i = 0; i <= nb_rows; i++) {
        result[i] = malloc(sizeof(int *) * nb_rows + 2);
    }
    return (result);
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

void big_int(char pos, int hight, int k, big *a)
{
    if(pos > a->pos) {
        a->pos = pos;
        a->hight = hight;
        a->k = k;
            }
    return;
}

char **put_x(char **str, big *a)
{
    int hight = 0;
    int hi = a->hight;
    int count = 0;
    int k = a->k;
    int pos = a->pos - '0';

    while (hight < pos) {
        while (count < pos) {
            str[hi][k] = 'x';
            k = k - 1;
            count = count + 1;
        }
        hi = hi - 1;
        count = 0;
        k = a->k;
        hight = hight + 1;
    }
    return (str);
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

char **bq(char **str, int rows, int cols)
{
    int hight = 2;
    int lon = 1;
    int k = 1;
    big a;

    while (hight < rows) {
        while (str[hight][k] != '\n') {
            if (str[hight][k] == '1') {
                str[hight][k] = bsq(str[hight][k-1], str[hight-1][k-1], str[hight-1][k]);
                big_int(str[hight][k], hight, k, &a);
            }
            k = k + 1;
        }
        k = 1;
        hight = hight + 1;
    }
    str = put_x(str, &a);
    show_square(str, rows, cols);
}

int main(int arc, char **arg)
{
    char buff[2000000];
    int fd = 0;
    int rows;
    int count;
    int cols;

    fd = open(arg[1], O_RDONLY);
    count = read(fd, buff, 1000000);
    buff[count+1] = '\0';
    close(fd);
    rows = get_line(buff);
    rows = rows + 1;
    cols = get_cols(buff);
    char **copy = mem_alloc_2d_array(rows, cols);
    copy = load_2d_arr_from_file(buff, rows, cols);
    bq(copy, rows, cols);
    return (0);
}
