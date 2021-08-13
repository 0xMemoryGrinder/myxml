/*
** EPITECH PROJECT, 2020
** my_xmlloader.c
** File description:
** header for my_xmlloader.c
*/

#include "../include/myxml_utils.h"
#include "my_puterr.h"

static int myxml_node_parse(myxml_reader_t *reader)
{
    int good;

    if (reader->source[reader->i] == '<') {
        reader->lex[reader->idx] = '\0';
        myxml_tag_data_get(reader);
        good = myxml_tag_check_close(reader);
        if (good == 1)
            return 1;
        if (!good)
            return 0;
        else if (reader->i != 0)
            reader->curr = myxml_node_create(reader->curr);
        reader->i++;
        if (!reader->curr || !myxml_tag_write(reader))
            return 0;
        return 1;
    }
    return -1;
}

static int myxml_doc_iterate(myxml_reader_t *reader)
{
    int good;

    for (reader->i = 0; reader->source[reader->i] != '\0'; ) {
        good = myxml_node_parse(reader);
        if (good == 1)
            continue;
        else if (!good)
            return 0;
        else
            reader->lex[reader->idx++] = reader->source[reader->i++];
    }
    return 1;
}

myxml_doc_t *myxml_doc_load(const char *path)
{
    myxml_doc_t *doc = malloc(sizeof(myxml_doc_t));
    myxml_reader_t reader;
    int good;

    if (!path)
        return NULL;
    reader.source = myxml_filepath_load(path);
    reader.idx = 0;
    doc->root = myxml_node_create(NULL);
    if (doc == NULL || reader.source == NULL || doc->root == NULL)
        return my_puterr("Error loading doc", __FILE__, __LINE__).ptr;
    doc->path = path;
    reader.curr = doc->root;
    good = myxml_doc_iterate(&reader);
    free(reader.source);
    if (!good) {
        myxml_node_free(doc->root);
        return NULL;
    } return doc;
}