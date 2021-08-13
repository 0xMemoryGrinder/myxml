/*
** EPITECH PROJECT, 2021
** B-MUL-200 (GRAPHICAL)
** File description:
** myxml_attr_values_set
*/

#include "my_puterr.h"
#include "myxml_utils.h"
#include "my.h"

int myxml_attr_set_int(char *name, myxml_node_t *node, int value)
{
    myxml_attr_list_t list = node->attributes;

    for (int index = 0; index < list.size; index++) {
        if (!myxml_strcmp(name, list.data[index].key)) {
            list.data[index].value = my_strnum(value);
            return list.data[index].value ? 1 : 0;
        }
    }
    return -1;
}

int myxml_attr_set_str(char *name, myxml_node_t *node, char *value)
{
    myxml_attr_list_t list = node->attributes;

    for (int index = 0; index < list.size; index++) {
        if (!myxml_strcmp(name, list.data[index].key)) {
            list.data[index].value = my_strdup(value);
            return list.data[index].value ? 1 : 0;
        }
    }
    return -1;
}

int myxml_attr_set_float(char *name, myxml_node_t *node, float value)
{
    myxml_attr_list_t list = node->attributes;

    for (int index = 0; index < list.size; index++) {
        if (!myxml_strcmp(name, list.data[index].key)) {
            list.data[index].value = my_strnum_f(value, 5);
            return list.data[index].value ? 1 : 0;
        }
    }
    return -1;
}

int myxml_attr_set_toggle(char *name, myxml_node_t *node, int value)
{
    myxml_attr_list_t list = node->attributes;

    for (int index = 0; index < list.size; index++) {
        if (!myxml_strcmp(name, list.data[index].key)) {
            list.data[index].value = myxml_strdup(value ? "ON" : "OFF");
            return list.data[index].value ? 1 : 0;
        }
    }
    return -1;
}