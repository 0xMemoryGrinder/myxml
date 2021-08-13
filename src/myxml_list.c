/*
** EPITECH PROJECT, 2020
** xml_node_list.c
** File description:
** header for xml_node_list.c
*/

#include <stdlib.h>
#include "../include/myxml_utils.h"

int myxml_node_list_init(myxml_node_list_t *list)
{
    list->size = 0;
    list->h_size = 1;
    list->data = malloc(sizeof(myxml_node_t *) * list->h_size);

    if (list->data == NULL)
        return 0;
    return 1;
}

int myxml_node_add(myxml_node_t *add, myxml_node_list_t *list)
{
    while (list->size >= list->h_size) {
        list->h_size *= 2;
        list->data = mem_expand(list->data, sizeof(myxml_node_t *) *
        list->size, sizeof(myxml_node_t *) * list->h_size);
        if (list->data == NULL)
            return 0;
    }
    list->data[list->size++] = add;
    return 1;
}

int myxml_attr_list_init(myxml_attr_list_t *list)
{
    list->size = 0;
    list->h_size = 1;
    list->data = malloc(sizeof(myxml_attr_t) * list->h_size);

    if (list->data == NULL)
        return 0;
    return 1;
}

int myxml_attr_add(myxml_attr_t *add, myxml_attr_list_t *list)
{
    while (list->size >= list->h_size) {
        list->h_size *= 2;
        list->data = mem_expand(list->data,
        sizeof(myxml_attr_t) * list->size,
        sizeof(myxml_attr_t) * list->h_size);
        if (list->data == NULL)
            return 0;
    }
    list->data[list->size++] = *add;
    return 1;
}

int myxml_attr_create(char *key, char *value, myxml_node_t *node)
{
    myxml_attr_t new = {myxml_strdup(key), myxml_strdup(value)};

    if (!new.key || !new.value || !myxml_attr_add(&new, &node->attributes))
        return 0;
    return 1;
}