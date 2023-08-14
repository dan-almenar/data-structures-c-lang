struct Node {
    double value;
    struct Node* nextNode;
};

typedef struct Node NODE;

typedef struct lList {
    unsigned int length;
    NODE* head;
    NODE* tail;
} LLIST;

// Returns a pointer to an empty Link List
LLIST* newLinkList();

// Safely deletes the entire link list
int delLinkList(LLIST* l);

// Adds a new node to the link list
// If the list is empty, the new node is set as the head
// otherwise the new node is set as the tail
NODE* addNode(LLIST* l, double val);

// Deletes the first node with the value val from the link list.
// Returns -1 if no node holds the value
int deleteNode(LLIST* l, double val);

// returns the first node with the value val (NULL if non)
NODE* findNode(LLIST* l, double val);

// Inserts a new node at the specified index
// If the index is greater than the list's lengh,
// the new node is inserted as the lists's tail.
NODE* insertNode(LLIST* l, double val, unsigned int index);

// removes the current head from the list
NODE* popHead(LLIST* l);

// removes current tail from the list
NODE* popTail(LLIST* l);

// prints every node's index and value
void printList(LLIST* l);