#include "Stack.h"
#include "Utils.h"
#include <iostream>

int main()
{
    std::cout << "=== Part 2.2 - Stack (LinkedList based) - main2.cpp ===" << std::endl;

    // ---- Test 1: Basic Stack operations ----
    std::cout << "\n--- Test 1: initStack / isEmpty / push / pop / isFull / cleanStack ---" << std::endl;
    Stack s;
    initStack(&s);

    std::cout << "isEmpty after init: " << isEmpty(&s) << " (expected 1 - true)" << std::endl;

    std::cout << "Pushing: 11 22 33 44 55" << std::endl;
    push(&s, 11);
    push(&s, 22);
    push(&s, 33);
    push(&s, 44);
    push(&s, 55);

    std::cout << "isEmpty after pushes: " << isEmpty(&s) << " (expected 0 - false)" << std::endl;
    std::cout << "isFull (linked list never full): " << isFull(&s) << " (expected 0)" << std::endl;

    std::cout << "Popping all (should be LIFO 55 44 33 22 11): ";
    while (!isEmpty(&s))
    {
        std::cout << pop(&s) << " ";
    }
    std::cout << std::endl;

    std::cout << "pop on empty (should be -1): " << pop(&s) << std::endl;
    std::cout << "isEmpty after pops: " << isEmpty(&s) << " (expected 1)" << std::endl;

    cleanStack(&s);

    // ---- Test 2: reverse() ----
    std::cout << "\n--- Test 2: reverse() ---" << std::endl;
    int nums1[] = { 1, 2, 3, 4, 5 };
    int size1 = 5;
    std::cout << "Before reverse: ";
    for (int i = 0; i < size1; ++i) std::cout << nums1[i] << " ";
    std::cout << std::endl;

    reverse(nums1, size1);

    std::cout << "After reverse:  ";
    for (int i = 0; i < size1; ++i) std::cout << nums1[i] << " ";
    std::cout << " (expected: 5 4 3 2 1)" << std::endl;

    int nums2[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    reverse(nums2, 10);
    std::cout << "reverse([2..20 step2]): ";
    for (int i = 0; i < 10; ++i) std::cout << nums2[i] << " ";
    std::cout << " (expected: 20 18 16 14 12 10 8 6 4 2)" << std::endl;

    // ---- Test 3: reverse10() ----
    std::cout << "\n--- Test 3: reverse10() ---" << std::endl;
    std::cout << "Please enter 10 integers separated by space (e.g. 1 2 3 4 5 6 7 8 9 10):" << std::endl;
    int* reversed10 = reverse10();

    std::cout << "Reversed 10: ";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << reversed10[i] << " ";
    }
    std::cout << std::endl;

    delete[] reversed10;

    std::cout << "\n=== All main2 tests finished ===" << std::endl;
    return 0;
}