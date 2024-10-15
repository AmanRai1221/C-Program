#include <stdio.h>
// Function to perform linear search iteratively
int linearSearch(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}
int main() {
    int arr[] = {4, 7, 11, 12, 16, 23, 35, 50, 70, 81};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the key value to search: ");
    scanf("%d", &key);
    int result = linearSearch(arr, n, key);
    if (result == -1) {
        printf("Key not found in the array.\n");
    } else {
        printf("Key found at index %d.\n", result);
    }
    return 0;
}
