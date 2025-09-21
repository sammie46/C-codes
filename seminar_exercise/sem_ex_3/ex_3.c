#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertNumber(int arr[], int *length, int num, int pos) {
    if (*length >= SIZE) {
        printf("The masive is full!\n");
        return;
    }
    if (pos < 0 || pos > *length) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *length; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;
    (*length)++;
}
int main() {
    int arr[SIZE] = {0};
    int length = 0;
    int num, pos;

    printf("Enter up to 10 numbers:\n");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &num);
        if (num == -1) break;
        arr[length++] = num;
    }

    printf("Enter numbers and positions (for end enter 0):\n");
    while (length < SIZE) {
        scanf("%d", &num);
        if (num == 0) break;
        scanf("%d", &pos);
        insertNumber(arr, &length, num, pos);
    }

    printArray(arr, length);

    return 0;
}

