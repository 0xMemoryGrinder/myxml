/*
** EPITECH PROJECT, 2020
** my_xml_cl.h
** File description:
** header for my_xml_cl.c
*/

#ifndef MY_XML_MY_XML_H
#define MY_XML_MY_XML_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct myxml_node_s myxml_node_t;

typedef struct {
    char *key;
    char *value;
} myxml_attr_t;

typedef struct {
    int h_size;
    int size;
    myxml_attr_t *data;
} myxml_attr_list_t;


typedef struct {
    int h_size;
    int size;
    myxml_node_t **data;
} myxml_node_list_t;

struct myxml_node_s{
    char *tag;
    char *data;
    struct myxml_node_s *parent;
    myxml_attr_list_t attributes;
    myxml_node_list_t children;
};

typedef struct {
    myxml_node_t *root;
    const char *path;
} myxml_doc_t;

typedef struct {
    char lex[1024];
    int idx;
    char *source;
    int i;
    myxml_node_t *curr;
    myxml_attr_t attr;
} myxml_reader_t;


// load xml doc
myxml_doc_t *myxml_doc_load(const char *path);

// write xml doc
void myxml_doc_write(myxml_doc_t *doc, char *path);

// allocs
myxml_node_t *myxml_node_create(myxml_node_t *parent);
int myxml_attr_list_init(myxml_attr_list_t *list);
int myxml_node_list_init(myxml_node_list_t *list);

// management
int myxml_attr_create(char *key, char *value, myxml_node_t *node);
int myxml_node_add(myxml_node_t *add, myxml_node_list_t *list);
int myxml_attr_add(myxml_attr_t *add, myxml_attr_list_t *list);


// destroyers
void myxml_node_free(myxml_node_t *node);
void myxml_attr_list_free(myxml_attr_list_t *list);


//set attributes
int myxml_attr_set_str(char *key, myxml_node_t *node, char *value);
int myxml_attr_set_int(char *key, myxml_node_t *node, int value);
int myxml_attr_set_float(char *key, myxml_node_t *node, float value);
int myxml_attr_set_toggle(char *name, myxml_node_t *node, int value);

// extract data
char *myxml_attr_value_str(char *key, myxml_node_t *node, int *status);
float myxml_attr_value_float(char *key, myxml_node_t *node, int *status);
int myxml_attr_value_int(char *key, myxml_node_t *node, int *status);
int myxml_attr_value_toggle(char *tag , myxml_node_t *node, int *status);


int myxml_child_data_extract_int(char *tag, myxml_node_t *node);
float myxml_child_data_extract_float(char *tag, myxml_node_t *node);
char *myxml_child_data_extract_str(char *tag, myxml_node_t *node, int *status);

void myxml_node_children_reset(myxml_node_t *node);
myxml_node_t *myxml_child_extract(char *tag, myxml_node_t *node, int recurs);

#endif //MY_XML_MY_XML_H
