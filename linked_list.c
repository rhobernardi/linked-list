#include "linked_list.h"

void run_prompt()
{
    printf("\nWelcome!\nType \"help\" to check available commands.\n\n");
    char command[30];
    char number[4];

    Node *list;
    list = (Node *) malloc(sizeof(Node));
    list->next = NULL;

    while(1)
    {
        printf("prompt-> ");
        fscanf (stdin, "%s", command);
        fgets (number, 100, stdin);

        if(strcmp(command, "exit") == 0) break;

        linked_list(list, command, atoi(number));
        printf("\n\n");
    }
    return;
}

void help()
{
    printf("\nCOMMANDS:\n\n");
    printf("help \t\t\t-  Shows this help.\n");
    printf("put [number] \t\t-  Insert a value in the list.\n");
    printf("get [number] \t\t-  Gets the value of a given position.\n");
    printf("remove [position] \t-  Removes the element in the given position.\n");
    printf("list \t\t\t-  Prints the entire list.\n");
    printf("first \t\t\t-  Prints the first content of the list.\n");
    printf("last \t\t\t-  Prints the lat content of the list.\n");
    printf("sort \t\t\t-  Runs Bubble Sort in the list.\n");
    printf("exit \t\t\t-  Closes the prompt.\n");
    return;
}

int is_empty (Node *n) {
    return n->next == NULL ? 1 : 0;
}

void print_list(Node *n)
{
    if(is_empty(n)) 
    {
        printf("LIST IS EMPTY");
        return;
    };

    Node *p;
    for (p = n->next; p != NULL; p = p->next)
        printf ("%d ", p->content);
    return;
}

int list_length = 0;

void add_node(Node *n, int content)
{
    Node *new_node, *p;
    new_node = (Node *) malloc(sizeof(Node));
    new_node->content = content;
    new_node->next = NULL;

    if(is_empty(n)) n->next = new_node;
    else 
    {
        for (p = n->next; p != NULL; p = p->next)
        {
            if(p->next == NULL)
            {
                p->next = new_node;
                break;
            }
        }
    }
    list_length++;
    return;
}

void get_content(Node *n, int position)
{
    if(is_empty(n)) 
    {
        printf("LIST IS EMPTY");
        return;
    }

    Node *p;
    int i = 1;

    for (p = n->next; p != NULL; p = p->next)
    {
        if(i == position)
        {
            printf ("%d", p->content);
            break;
        }
        i++;
    }
    if(i < position) printf("LIST LENGTH IS %d", i-1);
    return;
}

void remove_node(Node *n, int position)
{
    if(is_empty(n)) return;
    if(position > list_length) {printf("LIST LENGTH IS %d\n", list_length); return;}

    Node *p, *wanted_node;
    int i = 0;

    for (p = n; p != NULL; p = p->next)
    {
        if(i+1 == position)
        {
            wanted_node = p->next;
            printf ("%d\n", wanted_node->content);
            p->next = wanted_node->next;
            free(wanted_node);
            list_length--;
            break;
        }
        i++;
    }
    return;
}

void clear_list(Node *n) 
{
    Node *p, *q;
    p = n->next;
    while(p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    n->next = NULL;
}

void swap(Node *p, Node *q) 
{ 
    int temp = p->content; 
    p->content = q->content; 
    q->content = temp; 
} 

void bubbleSort(Node *n) 
{ 
    // Se lista vazia, retorna
    if (is_empty(n)) return; 
    
    Node *p; 
    Node *prev = NULL; 
    int swapped; 
  
    do
    { 
        swapped = 0; 
        p = n->next; 
        while (p->next != prev) 
        { 
            if (p->content > p->next->content) 
            {  
                swap(p, p->next); 
                swapped = 1; 
            } 
            p = p->next; 
        } 
        prev = p; 
    } 
    while (swapped); 
} 

void linked_list(Node *list, char *command, int number)
{   
    if(strcmp(command, "help") == 0) 
    {
        help();
    }

    else if(strcmp(command, "list") == 0) 
        print_list(list);
    
    else if(strcmp(command, "put") == 0) 
    {
        add_node(list, number);
        print_list(list);
    }

    else if(strcmp(command, "get") == 0) 
    {
        get_content(list, number);
    }

    else if(strcmp(command, "first") == 0) 
    {
        get_content(list, 1);
    }

    else if(strcmp(command, "last") == 0) 
    {
        get_content(list, list_length);
    }

    else if(strcmp(command, "remove") == 0) 
    {
        remove_node(list, number);
        print_list(list);
    }

    else if(strcmp(command, "clear") == 0) 
    {
        // while(!is_empty(list)) remove_node(list, 1);
        clear_list(list);
        print_list(list);
    }

    else if(strcmp(command, "sort") == 0) 
    {
        bubbleSort(list);
        print_list(list);
    }

    else printf("COMMAND NOT FOUND");
    return;
}