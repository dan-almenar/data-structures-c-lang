struct Node {
    double value;
    struct Node* nextNode;
};

typedef struct Node NODE;

typedef struct Stack {
    int length;
    NODE* head;
    NODE* tail;
} STACK;

// Creates an empty Stack
STACK* newStack();

// Safely deletes a Stack
int delStack(STACK* s);

// Adds a Node to a Stack
NODE* pushNode(STACK* s, double val);

// Removes a Node from a Stack
NODE* popNode(STACK* s);

// Prints a Stack current state
void printStack(STACK* s);