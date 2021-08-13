/*
** EPITECH PROJECT, 2020
** my_puterr.h
** File description:
** header for my_puterr.c
*/

#ifndef LIB_MYCSFML_MY_PUTERR_H
#define LIB_MYCSFML_MY_PUTERR_H


typedef union error_code_u {
    int nb;
    void *ptr;
}status_code_t;

static const status_code_t status_code_g = {0};

status_code_t my_puterr(char const *str,  char *filename, int line);

#endif //LIB_MYCSFML_MY_PUTERR_H
