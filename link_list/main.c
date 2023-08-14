#include <stdio.h>

#include "llist.h"

int main(){
    LLIST* l = newLinkList();
    NODE* test = NULL;
    int result;

    addNode(l, 1);
    addNode(l, 2);
    addNode(l, 3);
    addNode(l, 4);
    addNode(l, 5);
    addNode(l, 100);
    test = findNode(l, 100);
    printList(l);

    printf("\n\n\nTEST VALUE: %02lf\n\n\n", test->value);

    puts("\n\n\nDeleting the value 4...");
    deleteNode(l, 4);

    puts("Attempting to delete the value 80...");
    deleteNode(l, 80);

    printList(l);

    puts("\n\n\nPopping head...");
    popHead(l);
    printList(l);

    puts("\n\n\nPopping tail...");
    popTail(l);
    printList(l);

    puts("Deleting the link list...");
    result = delLinkList(l);

    printf("\nThe outcome of deleting the link list is: %d\n\n", result);

    return 0;
}