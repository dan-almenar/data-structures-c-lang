#include <stdio.h>
#include <stdlib.h>

#include "llist.h"

// Returns a pointer to an empty Link List
LLIST* newLinkList(){
    LLIST* l = malloc(sizeof(LLIST));

    if (l != NULL){
        l->length = 0;
        l->head = NULL;
        l->tail = NULL;

        return l;
    } else {
        return NULL;
    }

}

// Safely deletes entire the link list
int delLinkList(LLIST* l){
    // we pop head until the list is empty
    while (l->head && l->length >= 0){
        popHead(l);
    }

    free(l);

    return 0;
}

// Adds a new node to the link list
// If the list is empty, the new node is set as the head
// otherwise the new node is set as the tail
NODE* addNode(LLIST* l, double val){
    NODE* n = malloc(sizeof(NODE));

    if (n != NULL){
        n->value = val;
        n->nextNode = NULL;

        if (l->length == 0){
            l->head = n;
        } else if (l->length == 1){
            l->tail = n;
            l->head->nextNode = n;
        } else {
            l->tail->nextNode = n;
            l->tail = n;
        }
    }

    l->length++;

    return n;
}

// Deletes the first node with the value val from the link list.
// Returns -1 if no node holds the value
int deleteNode(LLIST* l, double val){
    int retVal = -1;
    NODE *currentNode = NULL, *tmp = NULL;

    if (l->length){
        if (l->head->value == val){
            popHead(l);
            retVal = 0;
        } else {
            currentNode = l->head;
            while (currentNode->nextNode->value != val && currentNode->nextNode != l->tail){
                currentNode = currentNode->nextNode;
            }

            if (currentNode->nextNode->value == val){
                tmp = currentNode->nextNode;
                currentNode->nextNode = tmp->nextNode;

                tmp = NULL;
                free(tmp);

                l->length--;
                retVal = 0;
            }
        }
    }
    
    return retVal;
}

// returns the first node with the value val (NULL if non)
NODE* findNode(LLIST* l, double val){
    NODE* currentNode = NULL;

    // check for head
    if (l->length){
        currentNode = l->head;

        while (currentNode->value != val || currentNode != l->tail){
            currentNode = currentNode->nextNode;
        }
    }

    return currentNode;
}

// Inserts a new node at the specified index
// If the index is greater than the list's lengh,
// the new node is inserted as the lists's tail.
NODE* insertNode(LLIST* l, double val, unsigned int index){
    NODE* tmp = NULL;
    NODE* newNode = malloc(sizeof(NODE));
    
    int i = 0;

    if (newNode != NULL){
        newNode->value = val;

        if (l->length == 0){
            l->head = newNode;
        } else {
            if (index > l->length){
                // new tail
                tmp = l->tail;
                tmp->nextNode = newNode;
                newNode->nextNode = NULL;
                l->tail = newNode;
            } else {
                tmp = l->head;

                // find the index position
                while (i < (l->length - 1)){
                    tmp = tmp->nextNode;
                    i++;
                }
                newNode->nextNode = tmp->nextNode;
                tmp->nextNode = newNode;
            }
        }

        l->length++;
    }

    return newNode;
}

// removes the current head from the list
NODE* popHead(LLIST* l){
    NODE *newHead = NULL, *tmp;
    if (l->head != NULL){
        tmp = l->head;
        newHead = l->head->nextNode;
        l->head = newHead;

        if (l->length == 1){
            l->tail = NULL;    
        }

        free(tmp);
    }

    if (l->length > 0) l->length--;
    return newHead;
}

// removes current tail from the list
NODE* popTail(LLIST* l){
    NODE *newTail = l->head, *tmp = NULL;

    if (l->tail){
        // find the next to tail node
        while (newTail->nextNode != l->tail){
            newTail = newTail->nextNode;
        }

        tmp = l->tail;
        l->tail = newTail;

        tmp = NULL;
        free(tmp);

        l->length--;

        return l->tail;        
    } else {
        return NULL;
    }
}

// prints every node's index and value
void printList(LLIST* l){
    int i;
    NODE* currentNode = l->head;

    puts("Link List current state:");
    for (i = 0; i < l->length; i++){
        printf(
            "{Index: %02d - Value: %.4lf}\n",
            i, currentNode->value
        );

        currentNode = currentNode->nextNode;
    }

    printf("\nLink List total length: %02d\n", l->length);

    return;
}
