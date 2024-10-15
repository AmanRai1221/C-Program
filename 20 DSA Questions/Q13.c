#include <stdio.h>

// Function to perform binary search iteratively
int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the key value to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result == -1) {
        printf("Key not found in the array.\n");
    } else {
        printf("Key found at index %d.\n", result);
    }

    return 0;
}