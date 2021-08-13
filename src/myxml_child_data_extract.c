/*
** EPITECH PROJECT, 2020
** extract_node_data.c
** File description:
** header for extract_node_data.c
*/

#include "../include/myxml_utils.h"
#include "my_puterr.h"

int myxml_child_data_extract_int(char *tag, myxml_node_t *node)
{
    myxml_node_list_t list = node->children;

    for (int i = 0; i < list.size; i++) {
        if (!myxml_strcmp(tag, list.data[i]->tag))
            return myxml_getnbr(list.data[i]->data);
    }
    return 0;
}

float myxml_child_data_extract_float(char *tag, myxml_node_t *node)
{
    myxml_node_list_t list = node->children;

    for (int i = 0; i < list.size; i++) {
        if (!myxml_strcmp(tag, list.data[i]->tag))
            return myxml_getnbr_f(list.data[i]->data);
    }
    return 0.0f;
}

char *myxml_child_data_extract_str(char *tag, myxml_node_t *node, int *status)
{
    myxml_node_list_t list = node->children;
    char *str = NULL;

    for (int i = 0; i < list.size; i++) {
        if (myxml_strcmp(tag, list.data[i]->tag))
            continue;
        str = myxml_strdup(list.data[i]->data);
        if  (str == NULL) {
            *status = 0;
            return my_puterr("Error malloc child data str",
            __FILE__, __LINE__).ptr;
        }
        return str;
    }
    return NULL;
}