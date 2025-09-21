#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int findKthLargest(int arr[], int n, int k) {
    if (k > 0 && k <= n) {
        return arr[k - 1];
    } else {
        printf("Invalid number for K!\n");
        return -1;
    }
}

int main() {
    int n, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d whole numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter K: ");
    scanf("%d", &k);

    sortArray(arr, n);

    int result = findKthLargest(arr, n, k);
    if (result != -1) {
        printf("%d -th biggest number is: %d\n", k, result);
    }

    return 0;
}

