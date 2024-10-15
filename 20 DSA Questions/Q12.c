#include <stdio.h>
// Function to perform binary search recursively
int binarySearch(int arr[], int low, int high, int key) {
    // Base case: If the low index is greater than the high index, 
    // the key is not found in the array
    if (low > high) {
        return -1;
    }
    // Calculate the mid index
    int mid = (low + high) / 2;
    // If the key is found at the mid index, return the mid index
    if (arr[mid] == key) {
        return mid;
    }
    // If the key is less than the mid element, search in the left half
    else if (arr[mid] > key) {
        return binarySearch(arr, low, mid - 1, key);
    }
    // If the key is greater than the mid element, search in the right half
    else {
        return binarySearch(arr, mid + 1, high, key);
    }
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the key value to search: ");
    scanf("%d", &key);
    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1) {
        printf("Key not found in the array.\n");
    } else {
        printf("Key found at index %d.\n", result);
    }
    return 0;
}
