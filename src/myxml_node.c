/*
** EPITECH PROJECT, 2020
** xml_node.c
** File description:
** header for xml_node.c
*/

#include "myxml.h"
#include <stdlib.h>

myxml_node_t *myxml_node_create(myxml_node_t *parent)
{
    myxml_node_t *new = malloc(sizeof(myxml_node_t));

    if (new == NULL || !myxml_attr_list_init(&new->attributes) ||
    !myxml_node_list_init(&new->children))
        return NULL;
    new->parent = parent;
    new->data = NULL;
    new->tag = NULL;
    if (parent)
        myxml_node_add(new, &parent->children);
    return new;
}

void myxml_attr_list_free(myxml_attr_list_t *list)
{
    for (int i = 0; i < list->size; i++) {
        free(list->data[i].value);
        free(list->data[i].key);
    }
    if (list->data)
        free(list->data);
}

void myxml_node_free(myxml_node_t *node)
{
    if (node->tag)
        free(node->tag);
    if (node->data)
        free(node->data);
    myxml_attr_list_free(&node->attributes);
    if (node->children.size > 0) {
        for (int i = 0; i < node->children.size; i++)
            myxml_node_free(node->children.data[i]);
    }
    if (node->children.data)
        free(node->children.data);
    free(node);
}

void myxml_node_children_reset(myxml_node_t *node)
{
    for (int i = 0; i < node->children.size; i++)
        myxml_node_free(node->children.data[i]);
    free(node->children.data);
    myxml_node_list_init(&node->children);
}