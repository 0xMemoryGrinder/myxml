/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** header file that contains the prototypes of libmy.a
*/

#pragma once

#include <stdlib.h>

char *my_strdup(const char *str);
int len_until_char(const char *str, char c);
int count_char(const char *str, char c);
int my_nblen(int nb);
int my_max_div(int nb);
int check_int(char const *str, int nSize, int nb);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_isneg (int nb);
char *my_strcat(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy(char *dest, char const *src);
void my_putchar(char c);
int my_put_nbr(int nb);
void my_swap(void **a, void **b);
int my_putstr(char const *str);
int my_str_isnum(char const *str);
char *my_strnum(int nb);
int my_revstr (char *str);
void my_putstr_err(char const *str);
char *my_strndup(char *str, int n);
char **my_str_to_tab(const char *str, char separator);
void destroy_array(void **array);
float my_getnbr_f(char *str);
int my_isnum(const char *str);
int my_is_alpha(const char *str);
int find_str_in_str_array(const char **arr, const char *str);
int my_is_uppercase(const char *str);
int my_is_lowercase(const char *str);
void free_multiple_ptr(int n, ...);
char *my_multiple_strcat(int n, ...);
void my_memcpy(void *dest, void *src, size_t size);
void *mem_expand(void *data, size_t actual_size, size_t newsize);
char *my_strnum_f(float nb, size_t nb_decimals);