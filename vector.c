 /*
  * File: vector.c
  * Author: Christopher Cruz Rubert
  * Student #: 841-09-1908
  * Date: 10/14/2016
  * Purpose: This programs implements the vector interface
*/

#include "vector.h"    // for vector interface
#include <stdlib.h>    // for malloc and free
#include <stddef.h>    // for NULL definitions
#include <stdbool.h>  // for bool

struct vector {
    int capacity;       //current capacity of internal array
    void **data;        // pointer to array of pointers to generic data
    int size;           // number of elements.
};

// Define functions as prototypes
static void ensure_capacity(Vector *vct);

// Returns a new empty vector with the given initial capacity.
// Pre: init_cap > 0
Vector *create_vector(int init_cap) {
    Vector *vct = malloc(sizeof(Vector));
    vct->capacity = init_cap;
    if (init_cap <= 0)
        return NULL;
    vct->data = malloc(vct->capacity * sizeof(void*));
    vct->size = 0;
    return vct;
}

// Adds an element at the end of the given vector.
void add_vector(Vector *vct, const void *elem) {
    ensure_capacity(vct);
    vct->data[vct->size++] = elem;
}

// Ensures that the given stack has the capacity for addition.
static void ensure_capacity(Vector *vct) {
    if (vct->capacity == vct->size + 1)
        vct->capacity *= 2;
    void **temp = malloc(vct->capacity * sizeof(void*));

    for (int curr = 0; curr < vct->size; curr++)
        temp[curr] = vct->data[curr];
    free(vct->data);
    vct->data = temp;
}

// Inserts an element at the given index of the vector and
// returns a success indicator.
// Returns false if idx < 0 || idx > size_vector(vct).
bool insert_vector(Vector *vct, int idx, const void *elem) {
    if (idx < 0 || idx > size_vector(vct))
        return false;
    ensure_capacity(vct);

    for (int curr = vct->size; curr > idx; curr--)
        vct->data[curr] = vct->data[curr - 1];
    vct->data[idx] = elem;
    vct->size++;
}

// Removes and returns the element at the given index of the vector.
// Returns NULL if idx < 0 || idx >= size_vector(vct).
void *remove_vector(Vector *vct, int idx) {
    if (idx < 0 || idx >= size_vector(vct))
        return NULL;
    void *elem = vct->data[idx];
    vct->size--;

    for (int curr = idx; curr < vct->size; curr++)
        vct->data[curr] = vct->data[curr + 1];
    vct->data[vct->size] = NULL;
    return elem;
}

// Modifies the element at the given index of the vector and
// returns a success indicator.
// Returns false if idx < 0 || idx >= size_vector(vct).
bool set_vector(Vector *vct, int idx, const void *elem) {
    if (idx < 0 || idx >= size_vector(vct))
        return false;
    return vct->data[idx] = elem;
}

// Returns the element at the given index of the vector.
// Returns NULL if idx < 0 || idx >= size_vector(vct).
void *get_vector(const Vector *vct, int idx) {
    if (idx < 0 || idx >= size_vector(vct))
        return NULL;

    return vct->data[idx];
}

// Returns the number of elements in the given vector.
int size_vector(const Vector *vct) {
    return vct->size;
}

// Returns the index of the given element in the vector, if found.
// Returns -1 otherwise.  It performs a sequential search.
int find_vector(const Vector *vct, const void *elem,
                int (*compare)(const void *a, const void *b)) {
    for (int curr = 0; curr < vct->size; curr++)
        if ((*compare)(vct->data[curr], elem) == 0)
            return curr;
    return -1;
}

// Returns the index of the given element in the vector, if found.
// Returns -1 otherwise.  It performs a binary search.
// Pre: The given vector is sorted.
int binary_search_vector(const Vector *vct, const void *elem,
                         int (*compare)(const void *a, const void *b)) {
    int lo = 0, hi = vct->size-1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if ((*compare)(elem, vct->data[mid]) < 0)
            hi = mid - 1;
        else if ((*compare)(elem, vct->data[mid]) > 0)
            lo = mid + 1;
        else
            return mid;
    }
    return -1;
}

// Sorts the given vector.
void sort_vector(Vector *vct,
                 int (*compare)(const void *a, const void *b)) {
    for (int pos = 0; pos < vct->size - 1; pos++) {
        int minIndx = pos;
        for (int idx = pos + 1; idx < vct->size; idx++) {
            if ((*compare)(vct->data[idx],vct->data[minIndx]) < 0)
                minIndx = idx;
        }
        if (minIndx != pos) {
            void **temp = vct->data[minIndx];
            vct->data[minIndx] = vct->data[pos];
            vct->data[pos] = temp;
        }
    }
}

// Iterates through the given vector using a visit function.
void iterate_vector(const Vector *vct,
                    void (*visit)(const void *elem)) {
    for (int curr = 0; curr < vct->size; curr++)
        (*visit)(vct->data[curr]);
}

// Deallocates the memory of the given vector.
void destroy_vector(Vector *vct) {
    free(vct->data);
    free(vct);
}
