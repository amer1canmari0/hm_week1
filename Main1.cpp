#include <iostream>
#include "Queue.h"

using namespace std;

// Helper to print queue contents since Queue doesn't have a print() method
void printQueue(Queue* q) 
{
    cout << "[ ";
    for (unsigned int i = 0; i < q->count; i++) {
        int idx = (q->head + i) % q->maxSize;
        cout << q->values[idx] << " ";
    }
    cout << "] (count=" << q->count << ", head=" << q->head << ", tail=" << q->tail << ")" << endl;
}

int main() 
{
    cout << "=== Part 1: Array Based Queue Test ===" << endl;

    Queue q;
    initQueue(&q, 5u); // capacity 5

    cout << "\n1. Test isEmpty on new queue:" << endl;
    cout << "isEmpty: " << (isEmpty(&q) ? "true (PASS)" : "false (FAIL)") << endl;
    cout << "isFull: " << (isFull(&q) ? "true" : "false (expected false)") << endl;
    printQueue(&q);

    cout << "\n2. Enqueue 3 items: 10, 20, 30" << endl;
    enqueue(&q, 10u);
    enqueue(&q, 20u);
    enqueue(&q, 30u);
    cout << "Queue after enqueues: ";
    printQueue(&q);
    cout << "Size should be 3, size = " << q.count << endl;
    // peek is values[head]
    if (!isEmpty(&q)) 
    {
        cout << "Front (peek) should be 10, peek = " << q.values[q.head] << endl;
    }

    cout << "\n3. Dequeue 1 item" << endl;
    int val = dequeue(&q);
    cout << "Dequeued: " << val << " (expected 10)" << endl;
    cout << "Queue now: ";
    printQueue(&q);
    if (!isEmpty(&q)) 
    {
        cout << "Front now should be 20, peek = " << q.values[q.head] << endl;
    }

    cout << "\n4. Fill queue to test isFull and circular array" << endl;
    enqueue(&q, 40u);
    enqueue(&q, 50u);
    enqueue(&q, 60u); // queue should be full now: [20,30,40,50,60]
    cout << "Queue after filling: ";
    printQueue(&q);
    cout << "isFull: " << (isFull(&q) ? "true (PASS)" : "false (FAIL)") << endl;
    cout << "Size: " << q.count << endl;

    cout << "\n5. Try to enqueue when full (should be ignored / handle overflow)" << endl;
    enqueue(&q, 70u);
    cout << "After trying to enqueue 70: ";
    printQueue(&q);
    cout << "Should still be full with 5 items: count = " << q.count << endl;

    cout << "\n6. Test circular behavior: dequeue 2, then enqueue 2" << endl;
    dequeue(&q);
    dequeue(&q);
    cout << "After 2 dequeues: ";
    printQueue(&q);
    enqueue(&q, 70u);
    enqueue(&q, 80u);
    cout << "After enqueuing 70, 80 (wrap-around): ";
    printQueue(&q);
    cout << "This proves circular array works" << endl;

    cout << "\n7. Dequeue all items until empty" << endl;
    while (!isEmpty(&q)) 
    {
        int d = dequeue(&q);
        cout << "Dequeued: " << d << " | Remaining: ";
        printQueue(&q);
    }
    cout << "isEmpty: " << (isEmpty(&q) ? "true (PASS)" : "false (FAIL)") << endl;

    cout << "\n8. Try to dequeue when empty (underflow test)" << endl;
    int x = dequeue(&q);
    cout << "Dequeue from empty returned: " << x << " (expected -1)" << endl;
    if (x == -1) 
    {
        cout << "Underflow handled correctly" << endl;
    }

    cleanQueue(&q);
    cout << "\n=== All tests finished, queue cleaned ===" << endl;
    return 0;
}