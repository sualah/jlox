#ifndef _MAIN_H
#define _MAIN_H
/**
 *
 *
 */
typedef struct Node
{
    char *value;
    Node *next;
    Node *prev;
} Node;

typedef struct DoublyLinkedList
{
    Node *head;
    Node *tail;
} DoublyLinkedList;

DoublyLinkedList*  createList();
Node* createNode(char *value);
void insert(char *value, DoublyLinkedList *list);
Node *find(struct DoublyLinkedList *list, char *value);
void delete(char *value, DoublyLinkedList *list);
void printList(struct DoublyLinkedList *list);
#endif