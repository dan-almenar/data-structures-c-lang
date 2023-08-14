#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(){
    STACK* s = newStack();
    int result;

    printf("Stack's tests...\n\n");
    if (s != NULL){
        pushNode(s, 1);
        pushNode(s, 2);
        pushNode(s, 3);

        printStack(s);

        pushNode(s, 4);
        pushNode(s, 5);
        pushNode(s, 6);

        printStack(s);

        printf("Popping last two nodes...\n\n");

        popNode(s);
        popNode(s);

        printStack(s);

        printf("Attempting to delete Stack...\n\n");
        result = delStack(s);

        printf(
            "The result of deleting the stack is... %d\n\n"
            "All tests done!\n",
            result
        );
    } else {
        printf("An error ocurred while attempting to create a new stack...\n\n");
    }


    return 0;
}