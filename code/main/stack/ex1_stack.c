#include <stdio.h>
#include "stack.h"

int main() {
    Stack stack;
    stack_init(&stack, NULL);

    int element1 = 17;
    int element2 = 18;
    int element3 = 14332;

    // Push elements onto the stack
    stack_push(&stack, &element1);
    stack_push(&stack, &element2);
    stack_push(&stack, &element3);

    // Peek the top element
    int *top_element = (int *)stack_peek(&stack);
    if (top_element != NULL) {
        printf("Top element: %d\n", *top_element);
    }

    // Pop elements from the stack
    void *data;
    while (stack_size(&stack) > 0) {
        if (stack_pop(&stack, &data) == 0) {
            printf("Popped element: %d\n", *(int *)data);
        }
    }

    // Destroy the stack
    stack_destroy(&stack);

    return 0;
}