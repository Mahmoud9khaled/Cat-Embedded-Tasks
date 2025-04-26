#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if target is found
        }
    }
    return -1; // Return -1 if target is not found
}

int main() {
    int size, target;
    
    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    
    // Input array elements
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input the target value to search
    printf("Enter the target value to search: ");
    scanf("%d", &target);
    
    // Perform linear search
    int result = linearSearch(arr, size, target);
    
    // Display the result
    if (result != -1) {
        printf("Target value %d found at index %d.\n", target, result);
    } else {
        printf("Target value %d not found in the array.\n", target);
    }
    
    return 0;
}