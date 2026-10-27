#include "Queue.h"
#include <cstddef>

void initQueue(Queue* q, unsigned int size)
{
    q->values = new unsigned int[size];
    q->maxSize = size;
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}

void cleanQueue(Queue* q)
{
    if (q != nullptr && q->values != nullptr)
    {
        delete[] q->values;
        q->values = nullptr;
        q->maxSize = 0;
        q->head = 0;
        q->tail = 0;
        q->count = 0;
    }
}

void enqueue(Queue* q, unsigned int newValue)
{
    if (!isFull(q))
    {
        q->values[q->tail] = newValue;
        q->tail = (q->tail + 1) % q->maxSize;
        q->count++;
    }
}

int dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    unsigned int val = q->values[q->head];
    q->head = (q->head + 1) % q->maxSize;
    q->count--;
    return val;
}

bool isEmpty(Queue* q)
{
    return q->count == 0;
}

bool isFull(Queue* q)
{
    return q->count == q->maxSize;
}