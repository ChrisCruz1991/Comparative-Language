/*
 * Vector_test.c
 * By Antonio F. Huertas
 * This program tests common vector operations.
 */

#include "Vector.h"  // for Vector and its functions
#include <stdio.h>   // for puts, printf, scanf
#include <stddef.h>  // for NULL definition
#include <stdlib.h>  // for malloc, free
#include <string.h>  // for strcmp

// Declares functions using prototypes.
void show_vector(const Vector *vct);
void show_string(const void *elem);
int compare_strings(const void *a, const void *b);

// Starts the execution of the program.
int main(void) {
    Vector *vct = create_vector(10);
    puts("An empty vector has been created.");
    show_vector(vct);

    add_vector(vct, "cat");
    add_vector(vct, "tree");
    add_vector(vct, "house");
    add_vector(vct, "woman");
    add_vector(vct, "man");
    puts("\nAfter adding some elements...");
    show_vector(vct);

    insert_vector(vct, 1, "dog");
    insert_vector(vct, 3, "bicycle");
    insert_vector(vct, 5, "boat");
    puts("\nAfter inserting some elements...");
    show_vector(vct);

    printf("The element at index #5 is %s.\n", get_vector(vct, 5));

    set_vector(vct, 5, "ship");
    puts("\nAfter modifying an element...");
    show_vector(vct);

    printf("The element at index #5 is %s.\n", get_vector(vct, 5));

    puts("\nSearching for the ship...");
    int index = find_vector(vct, "ship", &compare_strings);
    if (index == -1)
        puts("The element was NOT found.");
    else
        printf("The element was found at index #%d.\n", index);

    sort_vector(vct, &compare_strings);
    puts("\nAfter sorting the vector...");
    show_vector(vct);

    puts("\nSearching for the ship...");
    index = binary_search_vector(vct, "ship", &compare_strings);
    if (index == -1)
        puts("The element was NOT found.");
    else
        printf("The element was found at index #%d.\n", index);

    char *elem = remove_vector(vct, 5);
    puts("\nAfter removing the element at index #5...");
    printf("The %s was removed.\n", elem);
    show_vector(vct);

    destroy_vector(vct);
    vct = NULL;
    puts("\nThe vector has been deallocated.");
    return 0;
}

// Displays the element of a vector.
void show_vector(const Vector *vct) {
    printf("This is the vector: [ ");
    iterate_vector(vct, &show_string);
    printf("].\nIt has %d elements.\n", size_vector(vct));
}

// Displays a string.
void show_string(const void *elem) {
    printf("%s ", (char *)elem);
}

// Returns the result of a string comparison.
int compare_strings(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

