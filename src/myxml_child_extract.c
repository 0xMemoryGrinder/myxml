/*
** EPITECH PROJECT, 2020
** extract_children.c
** File description:
** header for extract_children.c
*/

#include "../include/myxml_utils.h"

myxml_node_t *myxml_child_extract(char *tag, myxml_node_t *node, int recursive)
{
    myxml_node_t *child = NULL;
    if (!node)
        return NULL;
    for (int i = 0; i < node->children.size; i++) {
        if (!myxml_strcmp(tag, node->children.data[i]->tag))
            return node->children.data[i];
    }
    for (int i = 0; recursive && i < node->children.size; i++) {
        child = myxml_child_extract(tag, node->children.data[i], true);
        if (child)
            return child;
    }
    return NULL;
}