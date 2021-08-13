/*
** EPITECH PROJECT, 2020
** my_strdup.c
** File description:
** copy a string in an other created dynamicly
*/

#include <stdlib.h>

static char *myxml_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

int myxml_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}

char *myxml_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char *myxml_strdup(char const *src)
{
    int length = myxml_strlen(src);

    length++;
    char *cpy = malloc(length * sizeof(char));
    if (cpy == 0)
        return NULL;
    myxml_strcpy(cpy, src);
    return cpy;
}

char *myxml_strndup(char *str, int n)
{
    char *new = malloc(sizeof(char) * (n + 1));

    if (new == NULL)
        return NULL;
    myxml_strncpy(new, str, n);
    return new;
}