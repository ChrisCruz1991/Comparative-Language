/*
 * my_string_fns.c
 * By Antonio F. Huertas
 * This program defines some C string functions.
 */

#include <stdio.h>  // for printf, scanf, getchar, puts, gets
#include <ctype.h>  // for toupper

// Defines some symbolic constants
#define WORD_SIZE 21
#define LINE_SIZE 81

// Declares functions using prototypes.
void printData(const char *str);
int my_strlen(const char *str);
int my_strcmp(const char *str1, const char *str2);
void my_strcpy(char *dst, const char *src);
void my_strcat(char *dst, const char *src);
void strtoupper(char *str);
int strtoint(const char *str);

// Starts the execution of the program.
int main(void) {
    char str1[LINE_SIZE] = "example string";
    puts("This is str1...");
    printData(str1);

    str1[0] = toupper(str1[0]);
    puts("After toupper to first character, this is str1...");
    printData(str1);

    my_strcpy(str1, "another");
    puts("After strcpy, this is str1...");
    printData(str1);

    my_strcat(str1, " thing");
    puts("After strcat, this is str1...");
    printData(str1);

    char str2[WORD_SIZE];
    printf("Enter a one-word string: ");
    scanf("%s", str2);

    puts("This is str2...");
    printData(str2);

    while (getchar() != '\n');   // flush keyboard buffer

    char str3[LINE_SIZE];
    printf("Enter a line of text: ");
    gets(str3);

    puts("This is str3...");
    printData(str3);

    puts("Comparing str2 and str3...");
    int cmp = my_strcmp(str2, str3);
    if (cmp < 0)
        puts("str2 goes before str3.");
    else if (cmp > 0)
        puts("str2 goes after str3.");
    else
        puts("str2 and str3 are the same.");

    char *str4 = "read-only string";
    puts("\nThis is the string pointed by str4...");
    printData(str4);

    str4 = "another read-only";
    puts("After reassingment, this is the string pointed by str4...");
    printData(str4);

    //modification
    char *str5 = "hello";
    puts("This is str5...");
    printData(str5);

    strtoupper(str5);
    puts("This is str5 in uppercase...");
    printData(str5);

    return 0;
}

// Prints the contents, first character and length of the given string.
void printData(const char *str) {
    printf("Contents: %s\n", str);
    printf("First character: %c\n", *str);
    printf("Length: %d\n\n", my_strlen(str));
}

// Returns the length of a string.
int my_strlen(const char *str) {
    const char *ptr = str;
    while (*ptr++ != '\0');
    return ptr - str - 1;
}

// Compares two strings lexicographically.
int my_strcmp(const char *str1, const char *str2) {
    while (*str1 == *str2 && *str1 != '\0') {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

// Copies the source string to a destination string.
void my_strcpy(char *dst, const char *src) {
    while ((*dst++ = *src++) != '\0');
}

// Appends the source string to a destination string.
void my_strcat(char *dst, const char *src) {
    while (*dst != '\0')
        dst++;
    while ((*dst++ = *src++) != '\0');
}

// Returns the uppercase equivalent of the string
void strtoupper(char *str) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z')
            str = toupper(str);
        str++;
    }
}
