/*
** EPITECH PROJECT, 2020
** my_xmlwriter.c
** File description:
** header for my_xmlwriter.c
*/

#include <bits/types/FILE.h>
#include <stdio.h>
#include "myxml.h"
#include "my.h"


static void myxml_attr(myxml_node_t *node, FILE *file)
{
    char *key;
    char *value;

    if (node->attributes.size > 0) {
        for (int i = 0; i < node->attributes.size; i++) {
            key = node->attributes.data[i].key;
            value = node->attributes.data[i].value;
            fwrite(" ", 1, sizeof(char), file);
            fwrite(key, my_strlen(key), sizeof(char), file);
            fwrite("=", 1, sizeof(char), file);
            fwrite("\"", 1, sizeof(char), file);
            fwrite(value, my_strlen(value), sizeof(char), file);
            fwrite("\"", 1, sizeof(char), file);
        }
    }
}

static void myxml_tag_closing(myxml_node_t *node, FILE *file, int tab_count)
{
    char *tab = "\t";

    if (tab_count > 0 && !node->data) {
        for (int i = 0; i < tab_count - 1; i++)
            fwrite(tab, 1, sizeof(char), file);
    }
    fwrite("</", 2, sizeof(char), file);
    fwrite(node->tag, my_strlen(node->tag), sizeof(char), file);
    fwrite(">\n", 2, sizeof(char), file);
}

static void endline(myxml_node_t *node, FILE *file)
{
    if (node->data) {
        fwrite(node->data, my_strlen(node->data), sizeof(char), file);
        myxml_tag_closing(node, file, 0);
    } else
        fwrite("\n", 1, sizeof(char), file);
}

static void myxml_write(myxml_node_t *node, FILE *file, int tab_count)
{
    if (tab_count > 0) {
        for (int i = 0; i < tab_count; i++)
            fwrite("\t", 1, sizeof(char), file);
    } fwrite("<", 1, sizeof(char), file);
    fwrite(node->tag, my_strlen(node->tag), sizeof(char), file);
    myxml_attr(node, file);
    if (node->children.size == 0 && node->data == NULL)
        fwrite("/>", 2, sizeof(char), file);
    else
        fwrite(">", 1, sizeof(char), file);
    endline(node, file);
    tab_count++;
    if (node->children.size > 0) {
        for (int i = 0; i < node->children.size; i++)
            myxml_write(node->children.data[i], file, tab_count);
        myxml_tag_closing(node, file, tab_count);
    }
}

void myxml_doc_write(myxml_doc_t *doc, char *path)
{
    FILE *newfile = fopen(path, "w");
    myxml_node_t *node = doc->root;

    if (newfile == NULL)
        return;
    myxml_write(node, newfile, 0);
    fclose(newfile);
}