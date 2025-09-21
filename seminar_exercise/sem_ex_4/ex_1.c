#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INITIAL_CAPACITY 10
#define MAX_COMMAND_LENGTH 100

int *elements = NULL;
int size = 0;
int capacity = 0;


void initialize() {
    capacity = INITIAL_CAPACITY;
    elements = (int *)malloc(capacity * sizeof(int)); 

    if (elements == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}

void resize_if_needed() {
    if (size >= capacity) {
        capacity *= 2;
        elements = (int *)realloc(elements, capacity * sizeof(int));

        if (elements == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
    }
}


void add(int x) {
    resize_if_needed();
    elements[size++] = x;
    printf("Added %d.\n", x);
}


void delete(int x) {
    int i, j = 0;

    for (i = 0; i < size; i++) {
        if (elements[i] != x) {
            elements[j++] = elements[i]; 
        }
    }

    if (j == size) {
        printf("%d not found.\n", x);
    } else {
        printf("Deleted all occurrences of %d.\n", x);
    }

    size = j;
}


int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b); 
}


void smallest(int x) {
    if (x <= 0 || x > size) {
        printf("Invalid position: %d.\n", x);
        return;
    }


    int *temp = (int *)malloc(size * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }


    for (int i = 0; i < size; i++) {
        temp[i] = elements[i];
    }


    qsort(temp, size, sizeof(int), compare);

    printf("The %d-th smallest number is %d.\n", x, temp[x - 1]);

    free(temp);  
}


void print_list() {
    printf("Current elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", elements[i]);
    }
    printf("\n");
}

int main() {
    initialize();

    char command[MAX_COMMAND_LENGTH]; 
    char operation[20];               
    int value;

    printf("Enter commands (add X, delete X, smallest X). Type 'exit' to quit.\n");


    while (1) {
        printf(">>> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (strncmp(command, "exit", 4) == 0) {
            break;
        }

        if (sscanf(command, "%s %d", operation, &value) == 2)
            {

            if (strcmp(operation, "add") == 0) {
                add(value);
            } else if (strcmp(operation, "delete") == 0) {
                delete(value);
            } else if (strcmp(operation, "smallest") == 0) {
                smallest(value);
            } else {
                printf("Unknown command.\n");
            }
        } else {
            printf("Invalid input. Please enter in format: command number\n");
        }

        print_list();
    }

    free(elements); 
    printf("Goodbye!\n");
    return 0;
}

