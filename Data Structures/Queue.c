#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void insertQueue(Node **queue, int data);
void printQueue(Node *queue);

Node *removeQueue(Node **queue);

void insertQueue(Node **queue, int data)
{   
    Node *temp, *node = (Node *) malloc(sizeof(Node));

    if(!node)
    {
        puts("\nMalloc failed");
        return;
    }

    node->next = NULL;
    node->data = data;

    if(!*queue)
    {
        *queue = node;
        return; 
    }

    temp = *queue;

    while(temp->next)
    {
        temp = temp->next;
    }

    temp->next = node;
}

void printQueue(Node *queue)
{
    while(queue)
    {
        printf("%d ", queue->data);
        queue = queue->next;
    }

    printf("\n");
}

Node *removeQueue(Node **queue)
{
    Node *remove = NULL;

    if(*queue)
    {
        remove = *queue;
        *queue = remove->next;
    }

    return remove;
}

int main(int argc, char **argv)
{
    Node *node = NULL;

    int value, i;

    do
    {
        printf("\n[0] - Exit");
        printf("\n[1] - Print Queue");
        printf("\n[2] - Enter a Value");
        printf("\n[3] - Remove Queue");
        printf("\n-> ");
        scanf(" %d", &i);

        switch (i)
        {
            case 1:
                printQueue(node);
                break;
            case 2:
                printf("\nEnter a value: ");
                scanf(" %d", &value);
                insertQueue(&node, value);
                break;
            case 3:
                removeQueue(&node);
                break;
        }
    } while(i);
}