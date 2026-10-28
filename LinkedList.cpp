#include "LinkedList.h"
#include <cstddef>

void initList(LinkedList* list) {
    if (list) list->head = nullptr;
}
void addToHead(LinkedList* list, unsigned int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}
int removeFromHead(LinkedList* list) {
    if (!list || !list->head) return -1;
    Node* temp = list->head;
    int value = (int)temp->data;
    list->head = temp->next;
    delete temp;
    return value;
}
void cleanList(LinkedList* list) {
    Node* cur = list->head;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    list->head = nullptr;
}
bool isListEmpty(LinkedList* list) {
    return !list || list->head == nullptr;
}