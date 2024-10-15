#include <stdio.h>
// Function to perform linear search recursively
int linearSearch(int arr[], int n, int key, int i) {
    // Base case: If the index is out of bounds, the key is not found
    if (i >= n) {
        return -1;
    }
    // If the key is found at the current index, return the index
    if (arr[i] == key) {
        return i;
    }
    // Recursively search the rest of the array
    return linearSearch(arr, n, key, i + 1);
}
int main() {
    int arr[] = {4, 5, 8, 12, 16, 27, 38, 66, 72, 81};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the key value to search: ");
    scanf("%d", &key);
    int result = linearSearch(arr, n, key, 0);
    if (result == -1) {
        printf("Key not found in the array.\n");
    } else {
        printf("Key found at index %d.\n", result);
    }
    return 0;
}
