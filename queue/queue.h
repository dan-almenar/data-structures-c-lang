struct Node {
    double value;
    struct Node* nextNode;
};

typedef struct Node NODE;

typedef struct Queue {
    unsigned int length;
    NODE* head;
    NODE* tail;
} QUEUE;

// Creates an empty Queue
QUEUE* newQueue();

// Safely deletes a Queue
int delQueue(QUEUE* q);

// Adds a node to a Queue
NODE* enqueue(QUEUE* q, double val);

// Removes a node to a Queue
NODE* dequeue(QUEUE* q);

// Prints a Queue's Nodes values
void printQueue(QUEUE* q);
