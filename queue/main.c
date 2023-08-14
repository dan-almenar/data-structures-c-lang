#include <stdio.h>

#include "queue.h"

int main(){
    int result;

    printf("Queue's module tests...\n\n");

    QUEUE* q = newQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printQueue(q);

    enqueue(q, 4);
    dequeue(q);
    dequeue(q);
    enqueue(q, 80);

    printQueue(q);

    result = delQueue(q);

    printf("\n\nThe result from deleting the Queue is: %d\n\n", result);
}