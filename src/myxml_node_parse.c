/*
** EPITECH PROJECT, 2020
** parse_xml_node.c
** File description:
** header for parse_xml_node.c
*/

#include "../include/myxml_utils.h"
#include "my_puterr.h"

int myxml_tag_check_close(myxml_reader_t *reader)
{
    char lex[1024];
    int idx = 0;

    if (reader->source[reader->i + 1] == '/') {
        reader->i += 2;
        while (reader->source[reader->i] != '>')
            lex[idx++] = reader->source[reader->i++];
        lex[idx] = '\0';
        if (!reader->curr)
            return my_puterr("Already at the root", __FILE__, __LINE__).nb;
        if (myxml_strcmp(reader->curr->tag, lex))
            return my_puterr("Closing tag doesn't match", __FILE__,
            __LINE__).nb;
        reader->curr = reader->curr->parent;
        (reader->i)++;
        return 1;
    }
    return -1;
}

static char *extract_data_untilchar(myxml_reader_t *reader, char c)
{
    while (reader->source[reader->i] && reader->source[reader->i] != c) {
        reader->lex[reader->idx++] = reader->source[reader->i++];
    }
    reader->lex[reader->idx] = '\0';
    return myxml_strndup(reader->lex, reader->idx);
}

int myxml_attr_get(myxml_reader_t *reader)
{
    if (reader->source[reader->i] == '=') {
        reader->lex[reader->idx] = '\0';
        reader->attr.key = myxml_strndup(reader->lex, reader->idx);
        if (!reader->attr.key)
            return 0;
        reader->idx = 0;
        return 1;
    }
    if (reader->source[reader->i] == '"') {
        reader->idx = 0;
        reader->i++;
        reader->attr.value = extract_data_untilchar(reader, '"');
        if (!reader->attr.value ||
        !myxml_attr_add(&reader->attr, &reader->curr->attributes))
            return 0;
        reader->idx = 0;
        reader->i++;
        return 1;
    }
    return -1;
}

int myxml_tag_data_get(myxml_reader_t *reader)
{
    if (reader->idx > 0 && !reader->curr->data && reader->lex[0] != '\n') {
        reader->curr->data = myxml_strndup(reader->lex, reader->idx);
        if (reader->curr->data == NULL)
            return 0;
        reader->idx = 0;
    } else if (reader->idx > 0 &&
    (reader->curr->data || reader->lex[0] == '\n'))
        reader->idx = 0;
    return 1;
}

int myxml_tag_write(myxml_reader_t *reader)
{
    int good;

    while (reader->source[reader->i] != '>') {
        reader->lex[reader->idx++] = reader->source[reader->i++];
        good = myxml_check_write_tag(reader);
        if (!good)
            return 0;
        else if (good == 1)
            continue;
        if (good == 12)
            break;
    } reader->lex[reader->idx] = '\0';
    if (!reader->curr->tag) {
        reader->curr->tag = myxml_strndup(reader->lex, reader->idx);
        if (reader->curr->tag == NULL)
            return my_puterr("Error with my_strndup", __FILE__, __LINE__).nb;
    } reader->idx = 0;
    reader->i++;
    return 1;
}