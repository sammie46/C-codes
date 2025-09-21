#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

void inputInitialArray(int arr[], int *size) {
    printf("Enter 10 initial numbers:\n");
    *size = 10;
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }

}

int insertAtIndex(int arr[], int *size, int value, int index) {
    if (*size >= MAX_SIZE) {
        printf("Array is full.\n");
        return 0;
    }

    if (index < 0 || index > *size) {
        printf("Invalid index: %d\n", index);
        return 0;
    }

    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1]; 
    }

    arr[index] = value;
    (*size)++;

    return 1;
}


void printArray(int arr[], int size) {
    printf("Final array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int array[MAX_SIZE];
    int size = 0;

    inputInitialArray(array, &size);

    printf("Enter pairs of number and index (0 to stop):\n");

    while (1) {
        int num, index;
        scanf("%d", &num);

        if (num == 0) break;

        scanf("%d", &index);

        insertAtIndex(array, &size, num, index);
    }

    printArray(array, size);

    return 0;
}

