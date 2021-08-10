#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* typedefine */
    /* return type */
    typedef union val{
        int ival;
        float fval;
        char *sval;
        bool bval;
    } val_t;

    /* Symbol table structure */
    typedef struct node{
        int index;
        int address;
        int lineno;
        char *name;
        char *type;
        char *element;
        struct node *next;
    } node_t;

    typedef struct ST {
        int scope;
        int index;
        node_t *head;
        struct ST *next;
    } symbol_table_t;

#endif /* COMMON_H */