/*
** EPITECH PROJECT, 2020
** myxml_utils.h
** File description:
** header for myxml_utils.c
*/

#ifndef MYXML_MYXML_UTILS_H
#define MYXML_MYXML_UTILS_H

#include "myxml.h"

int myxml_strlen(char const *str);
char *myxml_strdup(char const *src);
char *myxml_strndup(char *str, int n);
int myxml_strcmp(char const *s1, char const *s2);
int myxml_getnbr(char const *str);
float myxml_getnbr_f(char const *str);
void my_memcpy(void *dest, void *src, size_t size);
void *mem_expand(void *data, size_t actual_size, size_t newsize);


char *myxml_filepath_load(const char *filepath);
int myxml_tag_check_close(myxml_reader_t *reader);
int myxml_check_write_tag(myxml_reader_t *reader);
int myxml_attr_get(myxml_reader_t *reader);
int myxml_tag_data_get(myxml_reader_t *reader);
int myxml_tag_write(myxml_reader_t *reader);

void myxml_free_multiple_ptr(int n, ...);
char *myxml_multiple_strcat(int n, ...);

#endif //MYXML_MYXML_UTILS_H
