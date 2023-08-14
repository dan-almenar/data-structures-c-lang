#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

// Creates an empty Queue
QUEUE* newQueue(){
    QUEUE* nQueue = malloc(sizeof(QUEUE));

    if (nQueue != NULL){
        nQueue->length = 0;
        nQueue->head = NULL;
        nQueue->tail = NULL;
    }

    return nQueue;
}

// Safely deletes a Queue
int delQueue(QUEUE* q){
    while (q->length != 0){
        dequeue(q);
    }

    free(q);

    return 0;
}

// Adds a node to a Queue
NODE* enqueue(QUEUE* q, double val){
    NODE* newNode = malloc(sizeof(NODE));

    if (newNode != NULL){
        newNode->value = val;
        newNode->nextNode = NULL;

        if (!q->length){
            q->head = newNode;
        } else if (q->length == 1) {
            newNode->nextNode = q->head;
            q->tail = newNode;
        } else {
            newNode->nextNode = q->tail;
            q->tail = newNode;
        }

        q->length++;
    }

    return newNode;
}

// Removes a node to a Queue
NODE* dequeue(QUEUE* q){
    NODE *tmp = NULL;

    if (q->length){
        if (q->length == 1){
            q->head = NULL;
            q->length = 0;
        } else {
            tmp = q->tail;
            while (tmp->nextNode != q->head){
                tmp = tmp->nextNode;
            }

            tmp->nextNode = NULL;
            free(q->head);

            q->head = tmp;
            q->length--;
        }

        return q->head;
    } else {
        return NULL;
    }
}

// Prints a Queue's Nodes values
void printQueue(QUEUE* q){
    NODE* currentNode = NULL;
    int position;

    if (q->length == 0){
        printf("\nThe Queue is currently empty...\n");
    } else {
        currentNode = q->tail;
        printf(
            "\nQueue current state:\n"
            "Length: %d\n\n",
            q->length
        );

        position = q->length;

        while (currentNode != NULL){
            printf("{Position: %d - Value: %.4lf}\n", position, currentNode->value);
            currentNode = currentNode->nextNode;
            position--;
        }
    }

    return;
}