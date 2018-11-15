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

typedef struct big {
    char pos;
    int hight;
    int k;
} big;

#endif
