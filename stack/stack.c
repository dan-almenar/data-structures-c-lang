#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

// Creates an empty Stack
STACK* newStack(){
    STACK* s = malloc(sizeof(STACK));

    if (s != NULL){
        s->length = 0;
        s->head = NULL;
        s->tail = NULL;
    }

    return s;
}

// Safely deletes a Stack
int delStack(STACK* s){
    while (s->length){
        popNode(s);
    }

    free(s);

    return 0;
}

// Adds a Node to a Stack
NODE* pushNode(STACK* s, double val){
    NODE* newNode = malloc(sizeof(NODE));

    if (newNode != NULL){
        if (!s->length){
            newNode->value = val;
            s->head = newNode;
            newNode->nextNode = NULL;
        } else if (s->length == 1){
            newNode->nextNode = s->head;
            s->tail = newNode;
        } else {
            newNode->nextNode = s->tail;
            s->tail = newNode;
        }

        s->length++;
    }

    return newNode;
}

// Removes a Node from a Stack
NODE* popNode(STACK* s){
    // TODO REFACTOR THIS
    NODE* tmp = NULL;

    if (s->length){
        if (s->length == 1){
            tmp = s->head;
            s->head = NULL;
        } else {
            tmp = s->tail;
            s->tail = tmp->nextNode;
        }
        free(tmp);
        s->length--;
    }

    return s->tail;
}

// Prints a Stack current state
void printStack(STACK* s){
    NODE* currentNode = s->tail;
    int counter = s->length;

    if (!s->length){
        puts("Stack is currently empty...");
    } else {
        printf(
            "\nStacks's current status:\n"
            "Length: %d\n\n",
            s->length
        );
        while (currentNode != NULL){
            printf("{Position: %d - Value: %.4lf}\n", counter, currentNode->value);
            counter--;
            currentNode = currentNode->nextNode;
        }
    }

    putchar('\n');

    return;
}