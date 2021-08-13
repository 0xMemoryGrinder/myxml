/*
** EPITECH PROJECT, 2020
** parse_xml_node2.c
** File description:
** header for parse_xml_node2.c
*/

#include "myxml.h"
#include "../include/myxml_utils.h"

static int myxml_check_orphan_tag(myxml_reader_t *reader)
{
    if (reader->source[reader->i] == '/'
    && reader->source[reader->i + 1] == '>') {
        reader->lex[reader->idx] = '\0';
        if (!reader->curr->tag)
            reader->curr->tag = myxml_strndup(reader->lex, reader->idx);
        if (reader->curr->tag == NULL)
            return 0;
        reader->curr = reader->curr->parent;
        reader->i++;
        return 12;
    }
    return 1;
}

static int myxml_tag_get(myxml_reader_t *reader)
{
    if (reader->source[reader->i] == ' ' && !reader->curr->tag) {
        reader->lex[reader->idx] = '\0';
        reader->curr->tag = myxml_strndup(reader->lex, reader->idx);
        if (!reader->curr->tag)
            return 0;
        reader->idx = 0;
        reader->i++;
        return 1;
    }
    if (reader->source[reader->i - 1] == ' ') {
        reader->idx--;
    }
    return -1;
}

int myxml_check_write_tag(myxml_reader_t *reader)
{
    int good = myxml_tag_get(reader);

    if (!good)
        return 0;
    else if (good == 1)
        return 1;
    good = myxml_attr_get(reader);
    if (!good)
        return 0;
    else if (good == 1)
        return myxml_check_orphan_tag(reader);
    return -1;
}