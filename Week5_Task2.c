#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target, int *steps) {
    int left = 0;
    int right = size - 1;
    *steps = 0; // Initialize step counter

    while (left <= right) {
        (*steps)++; // Increment step counter
        int mid = left + (right - left) / 2; // To avoid potential overflow

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Target not found
}

int main() {
    int size, target, steps;
    
    // Input the size of the sorted array
    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    // Input sorted array elements
    printf("Enter %d sorted integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input the target value to search
    printf("Enter the target value to search: ");
    scanf("%d", &target);
    
    // Perform binary search
    int result = binarySearch(arr, size, target, &steps);
    
    // Display the result
    if (result != -1) {
        printf("Target value %d found at index %d.\n", target, result);
        printf("Number of steps taken: %d\n", steps);
    } else {
        printf("Target value %d not found in the array.\n", target);
        printf("Number of steps taken: %d\n", steps);
    }
    
    return 0;
}