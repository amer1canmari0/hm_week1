#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    unsigned int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

void initList(LinkedList* list);
void addToHead(LinkedList* list, unsigned int data);
int removeFromHead(LinkedList* list); 
void cleanList(LinkedList* list);
bool isListEmpty(LinkedList* list);

#endif