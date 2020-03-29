#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node 
{
    int content;
    struct node *next;
} Node;

void run_prompt();
void linked_list(Node *list, char *command, int number);

#endif