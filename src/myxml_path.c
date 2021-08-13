/*
** EPITECH PROJECT, 2020
** myxml_path.c
** File description:
** myxml_path.c
*/

#include "my_puterr.h"
#include "myxml.h"
#include "my.h"

static int myxml_path_create_missing_nodes(myxml_node_t *root, char **tab,
int idx)
{
    myxml_node_t *child = NULL;

    if (!tab[idx])
        return 1;
    child = myxml_node_create(root);
    if (!child)
        return my_puterr("Malloc error", __FILE__, __LINE__).nb;
    child->tag = my_strdup(tab[idx]);
    return myxml_path_create_missing_nodes(child, tab, idx + 1);
}

static int myxml_path_check_presence(myxml_node_t *root, char **tab, int idx)
{
    for (size_t i = 0; root->children.data[i]; ++i)
        if (!my_strcmp(root->children.data[i]->tag, tab[idx]))
            return myxml_path_check_presence(root->children.data[i], tab,
            idx + 1);
    return myxml_path_create_missing_nodes(root, tab, idx);
}

int myxml_path_create(myxml_doc_t *doc, char *path)
{
    char **tab = my_str_to_tab(path, '/');

    if (!tab)
        return my_puterr("Malloc error", __FILE__, __LINE__).nb;
    if (!myxml_path_check_presence(doc->root, tab, 0))
        return 0;
    for (size_t i = 0; tab[i]; ++i)
        free(tab[i]);
    free(tab);
    return 1;
}

static myxml_node_t *myxml_path_search(myxml_node_t *root, char **tab, int idx)
{
    myxml_node_t *node = myxml_child_extract(tab[idx], root, false);

    if (node) {
        if (tab[idx + 1])
            return myxml_path_search(node, tab, ++idx);
        return node;
    } else
        return NULL;
}

int myxml_path_get(myxml_doc_t *doc, char *path, myxml_node_t **node)
{
    char **tab = my_str_to_tab(path, '/');

    if (!tab) {
        *node = NULL;
        return my_puterr("Malloc error", __FILE__, __LINE__).nb;
    }
    *node = myxml_path_search(doc->root, tab, 0);
    if (!(*node))
        return -1;
    for (size_t i = 0; tab[i]; ++i)
        free(tab[i]);
    free(tab);
    return 1;
}