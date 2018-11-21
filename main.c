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

char **except(char **str, int rows, int cols)
{
    int i = 0;

    if (rows > 2 && cols > 2)
        return (str);
    if (rows == 2) {
        while (str[1][i] != '1')
            i++;
        str[1][i] = 'x';
    }
    if (cols == 2) {
        while (str[i][0] != '1') {
            i++;
        }
        str[i][0] = 'x';
    }
    return (str);
}

char **bq(char **str, int rows, int cols)
{
    int hight = 2;
    int lon = 1;
    int k = 1;
    big a = {48, 0, 0};

    while (hight < rows) {
        while (str[hight][k] != '\n') {
            if (str[hight][k] == '1') {
                str[hight][k] = bsq(str[hight][k-1],
                                    str[hight-1][k-1], str[hight-1][k]);
                big_int(str[hight][k], hight, k, &a);
            }
            k = k + 1;
        }
        k = 1;
        hight = hight + 1;
    }
    str = put_x(str, &a);
    str = except(str, rows, cols);
    show_square(str, rows, cols);
}

int main(int arc, char **arg)
{
    char buff[2000000];
    int fd = open(arg[1], O_RDONLY);
    int rows;
    int count;
    int cols;

    fd = open(arg[1], O_RDONLY);
    count = read(fd, buff, 100000000);
    buff[count+1] = '\0';
    close(fd);
    rows = get_line(buff);
    rows = rows + 1;
    cols = get_cols(buff);
    char **copy = mem_alloc_2d_array(rows, cols);
    copy = load_2d_arr_from_file(buff, rows, cols);
    bq(copy, rows, cols);
    free_2d(copy, rows, cols);
    return (0);
}
