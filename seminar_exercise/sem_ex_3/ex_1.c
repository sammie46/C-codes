#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void findLongestPlateau(int arr[], int n, int *start, int *length) {
    int maxLength = 1, maxStart = 0;
    int currentLength = 1, currentStart = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                maxStart = currentStart;
            }
            currentLength = 1;
            currentStart = i;
        }
    }
    if (currentLength > maxLength) {
        maxLength = currentLength;
        maxStart = currentStart;
    }

    *start = maxStart;
    *length = maxLength;
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input!\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input!\n");
            return 1;
        }
    }

    bubbleSort(arr, n);

    int start, length;
    findLongestPlateau(arr, n, &start, &length);
    printf("The longest ploshtatka starts from %d and is with lenght %d.\n", start, length);

    return 0;
}

