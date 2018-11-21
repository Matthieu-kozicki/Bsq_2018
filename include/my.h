/*
** EPITECH PROJECT, 2018
** my
** File description:
** h
*/

#ifndef MY_H
#define MY_H

void my_putchar(char c);
int my_put_nbr(int nb);
int get_cols(char *str);
int get_line(char *str);
void my_putstr(char const *str);
int my_strlen(char const *str);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
void free_2d(char **str, int nb_rows, int nb_cols);
char **load_2d_arr_from_file(char *str, int nb_rows, int nb_cols);
char bsq(char x, char y, char z);
char **show_square(char **str, int rows, int cols);

typedef struct big {
    char pos;
    int hight;
    int k;
} big;

void big_int(char pos, int hight, int k, big *a);
#endif
