/*
 * File: vector.c
 * Author: Christopher Cruz Rubert
 * Student #: 841-09-1908
 * This program implements a vector
*/

#include "vector.h"
#include <stdlib.h>
#include <stddef.h>

struct vector {
    int capacity;       //current capacity of internal array
    void **data;        // pointer to array of pointers to generic data
    int size;           // number of elements
};

// Returns a new empty vector with the given initial capacity.
// Pre: init_cap > 0
Vector *create_vector(int init_cap);

// Adds an element at the end of the given vector.
void add_vector(Vector *vct, const void *elem);

// Inserts an element at the given index of the vector and
// returns a success indicator.
// Returns false if idx < 0 || idx > size_vector(vct).
bool insert_vector(Vector *vct, int idx, const void *elem);

// Removes and returns the element at the given index of the vector.
// Returns NULL if idx < 0 || idx >= size_vector(vct).
void *remove_vector(Vector *vct, int idx);

// Modifies the element at the given index of the vector and
// returns a success indicator.
// Returns false if idx < 0 || idx >= size_vector(vct).
bool set_vector(Vector *vct, int idx, const void *elem);

// Returns the element at the given index of the vector.
// Returns NULL if idx < 0 || idx >= size_vector(vct).
void *get_vector(const Vector *vct, int idx);

// Returns the number of elements in the given vector.
int size_vector(const Vector *vct);

// Returns the index of the given element in the vector, if found.
// Returns -1 otherwise.  It performs a sequential search.
int find_vector(const Vector *vct, const void *elem,
                int (*compare)(const void *a, const void *b));

// Returns the index of the given element in the vector, if found.
// Returns -1 otherwise.  It performs a binary search.
// Pre: The given vector is sorted.
int binary_search_vector(const Vector *vct, const void *elem,
                         int (*compare)(const void *a, const void *b));

// Sorts the given vector.
void sort_vector(Vector *vct,
                 int (*compare)(const void *a, const void *b));

// Iterates through the given vector using a visit function.
void iterate_vector(const Vector *vct,
                    void (*visit)(const void *elem));

// Deallocates the memory of the given vector.
void destroy_vector(Vector *vct);
