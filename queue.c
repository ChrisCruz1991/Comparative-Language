/*
 * File: queue.c
 * Author: Christopher Cruz Rubert
 * Student #: 841-09-1908
 * This program implements the queue data structure
 */

 #include "queue.h"     // for QUEUEU and its functions
 #include <stdlib.h>    // for malloc and free
 #include <stddef.h>    // for NULL definitions

 // Defines Node as an alias for the node structure
typedef struct node Node;

// Declares the node structure
struct node {
    void *data;     //pointer to generic data
    Node *next;     // pointer to the next node in internal linked list
};

// Defines the queue structure
struct queue {
    Node *front;     // pointer to the front element
    Node *rear;      // pointer to the rear element
};

// Returns a new empty queue.
Queue *create_queue(void) {
    Queue *que = malloc(sizeof(Queue));
    que->front = que->rear = NULL;
    return que;
}

// Determines whether the given queue is empty.
bool is_empty_queue(const Queue *que) {
    return que->front == NULL;
}

// Adds an element to the rear of the given queue.
void enqueue(Queue *que, void *elem) {
    Node *curr = malloc(sizeof(Node));
    curr->data = elem;
    curr->next = NULL;
    if (que->front == NULL)
        que->front = que->rear = curr;

    else
        que->rear = que->rear->next = curr;
}

// Removes and returns the element at the front of the given queue.
// Returns NULL if the queue is empty.
void *dequeue(Queue *que) {
    if (is_empty_queue(que))
        return NULL;

    Node *temp = que->front;
    void *elem = temp->data;
    que->front = que->front->next;
    free(temp);

    if (que->front == NULL)
        que->rear = NULL;
    return elem;
}

// Iterates through the given queue using a visit function.
void iterate_queue(const Queue *que,
                   void (*visit)(void *elem)) {
        for (Node *curr = que->front; curr != NULL; curr = curr->next)
            (*visit)(curr->data);
}

// Deallocates the memory of the given queue.
void destroy_queue(Queue *que) {
    while (que->front != NULL) {
        Node *curr = que->front;
        que->front = que->front->next;
        free(curr);
    }
    que->rear = NULL;
    free(que);
}
