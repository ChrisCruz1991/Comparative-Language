/*
 * queue.h
 * By Antonio F. Huertas
 * Header (interface) file for a generic queue.
 */

#ifndef QUEUE_H       // prevents double inclusion
#define QUEUE_H

#include <stdbool.h>  // for bool

// Defines queue as an alias for an opaque structure.
typedef struct queue Queue;

// Returns a new empty queue.
Queue *create_queue(void);

// Determines whether the given queue is empty.
bool is_empty_queue(const Queue *que);

// Adds an element to the rear of the given queue.
void enqueue(Queue *que, void *elem);

// Removes and returns the element at the front of the given queue.
// Returns NULL if the queue is empty.
void *dequeue(Queue *que);

// Iterates through the given queue using a visit function.
void iterate_queue(const Queue *que,
                   void (*visit)(void *elem));

// Deallocates the memory of the given queue.
void destroy_queue(Queue *que);

#endif

