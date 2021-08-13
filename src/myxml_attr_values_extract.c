/*
** EPITECH PROJECT, 2020
** extract_xml_data.c
** File description:
** header for extract_xml_data.c
*/

#include "my_puterr.h"
#include "../include/myxml_utils.h"

int myxml_attr_value_int(char *key, myxml_node_t *node, int *status)
{
    myxml_attr_list_t list = node->attributes;
    int test;
    for (int i = 0; i < list.size; i++) {
        if (!myxml_strcmp(key, list.data[i].key)) {
            test = myxml_getnbr(list.data[i].value);
            return test;
        }
    }
    if (status)
        *status = -1;
    return 0;
}

float myxml_attr_value_float(char *key, myxml_node_t *node, int *status)
{
    myxml_attr_list_t list = node->attributes;

    for (int i = 0; i < list.size; i++) {
        if (!myxml_strcmp(key, list.data[i].key))
            return myxml_getnbr_f(list.data[i].value);
    }
    if (status)
        *status = -1;
    return 0.0f;
}

char *myxml_attr_value_str(char *key, myxml_node_t *node, int *status)
{
    myxml_attr_list_t list = node->attributes;
    char *str = NULL;

    for (int i = 0; i < list.size; i++) {
        if (myxml_strcmp(key, list.data[i].key))
            continue;
        str = myxml_strdup(list.data[i].value);
        if (str == NULL) {
            *status = 0;
            return my_puterr("Error malloc xml value str attribute",
            __FILE__, __LINE__).ptr;
        }
        *status = 1;
        return str;
    }
    *status = -1;
    return NULL;
}

static int myxml_check_toggle_value(char *toggle, int *status)
{
    if (!myxml_strcmp(toggle, "ON")) {
        free(toggle);
        *status = 1;
        return 1;
    } else if (!myxml_strcmp(toggle, "OFF")) {
        *status = 1;
        free(toggle);
        return 0;
    } free(toggle);
    *status = 0;
    return 0;
}

int myxml_attr_value_toggle(char *tag , myxml_node_t *node, int *status)
{
    static int debug_mode = 0;
    char *toggle = myxml_attr_value_str(tag, node, status);

    if (toggle && !myxml_strcmp(tag, "debug") && !myxml_strcmp(toggle, "ON"))
        debug_mode = 1;
    if (*status == 0 || !toggle) {
        if (*status == 0)
            return my_puterr("Error malloc toggle string",
            __FILE__, __LINE__).nb;
        if (!toggle && debug_mode)
            my_puterr("No such toggle attribute", __FILE__, __LINE__);
        return -1;
    }
    return myxml_check_toggle_value(toggle, status);
}