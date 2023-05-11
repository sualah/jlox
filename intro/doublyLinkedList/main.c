#include <stdio.h>
#include <main.h>
#include <stdlib.h>
#include <string.h>

DoublyLinkedList *createList()
{
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Node *createNode(char *value)
{
    Node *node = malloc(sizeof(Node));
    node->value = (char *)malloc(strlen(value) + 1);
    strcpy(node->value, value);
    node->next = NULL;
    node->prev = NULL;
    return node;
};

void insert(char *value, DoublyLinkedList *list)
{
    Node *node = createNode(value);

    if (list->head == NULL)
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
}
Node *find(struct DoublyLinkedList *list, char *value)
{
    Node *node = list->head;
    while (node != NULL)
    {
        if (strcmp(node->value, value) == 0)
        {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void delete(char *value, DoublyLinkedList *list)
{
    Node *node = find(list, value);
    if (node == list->head)
    {
        list->head = node->next;
    }

    if (node == list->tail)
    {
        list->tail = node->prev;
    }
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }

    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }

    free(node->value);
    free(node);
}
void printList(struct DoublyLinkedList *list)
{
    Node *node = list->head;
    while (node != NULL)
    {
        printf("%s\n", node->value);
        node = node->next;
    }
}


int main()
{
    DoublyLinkedList *list = createList();

    insert(list, "Alice");
    insert(list, "Bob");
    insert(list, "Charlie");
    insert(list, "David");
    printf("List after insertions:\n");
    printList(list);
    Node *node = find(list, "Charlie");
    if (node != NULL)
    {
        printf("Found node with value \"%s\"\n", node->value);
    }
    else
    {
        printf("Node not found\n");
    }
    delete (list, "Bob");
    return 0;
}
