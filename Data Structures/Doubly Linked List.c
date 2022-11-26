#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *previous;
}Node;

typedef struct List
{
    Node *initial;
    int size;
}List;

void printForwardList(List list);
void insertBeginning(List *list, int value);
void insertEnd(List *list, int value);
void printListBackwards(List list);

void insertBeginning(List *list, int value)
{
    Node *node = (Node *) malloc(sizeof(Node));

    node->next = list->initial;
    node->previous = NULL;
    node->value = value;

    if(list->initial)
        list->initial->previous = node;

    list->initial = node;
    list->size++;
}

void printListBackwards(List list)
{
    int i = 0;

    Node *node = list.initial;

    while(node)
    {
        if(node->next)
            node = node->next;
        else break;

        i++;
    }

    while(node)
    {
        printf("\nIndex[%d]: %d", i, node->value);
        node = node->previous;
        i--;
    }

    printf("\n");
    printf("\nSize of List: %d", list.size);
    printf("\n");
}

void printForwardList(List list)
{
    int i = 0;

    Node *node = list.initial;

    while(node)
    {
        printf("\nIndex[%d]: %d", i, node->value);
        node = node->next;
        i++;
    }

    printf("\n");
    printf("\nSize of List: %d", list.size);
    printf("\n");
}

void insertEnd(List *list, int value)
{
    Node *temp, *node = (Node *) malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;

    list->size++;

    if(!list->initial)
    {
        list->initial = node;
        node->previous = NULL;
        return;
    }

    temp = list->initial;

    while(temp->next)
    {
        temp = temp->next;
    }

    temp->next = node;
    node->previous = temp;

}

void removeNode(List *list, int value)
{
    Node *node = list->initial;

    Node *temp = NULL;

    if(list->initial && node->value == value)
    {
        temp = list->initial;
        list->initial = temp->next;
        if(list->initial)
            list->initial->previous = NULL;
        list->size--;
        free(temp);
        return;
    }

    while(node && node->next && node->next->value != value)
    {
        node = node->next;
    } 

    if(node && node->next)
    {
        temp = node->next;
        node->next = temp->next;
        if(node->next)
            node->next->previous = node;

    }

    if(temp)
    {
        free(temp);
        list->size--;
    }  
}

int main()
{
    List list;

    int scanner;
    int value;

    list.initial = NULL;
    list.size = 0;

    do {

        printf("\n0 - Exit");
        printf("\n1 - Print Forward List");
        printf("\n2 - Print List Backwards");
        printf("\n3 - Insert at the Beginning");
        printf("\n4 - insert at the End");
        printf("\n5 - Remove Node");
        printf("\n-> ");
        scanf(" %d", &scanner);

        if(scanner==1)
        {
            printForwardList(list);
        }
        else if(scanner==2)
        {
            printListBackwards(list);
        }
        else if(scanner==3)
        {
            printf("\nEnter a value: ");
            scanf(" %d", &value);
            insertBeginning(&list, value);
        }
        else if(scanner==4)
        {
            printf("\nEnter a value: ");
            scanf(" %d", &value);
            insertEnd(&list, value);    
        }
        else if(scanner==5)
        {
            printf("\nEnter a value: ");
            scanf(" %d", &value);
            removeNode(&list, value);
        }

    } while(scanner);

    return 0;
}

