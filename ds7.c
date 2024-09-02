#include <stdio.h>

int iterativeBinarySearch(int arr[], int size, int target);
int recursiveBinarySearch(int arr[], int left, int right, int target);

int main() {
    int array[100], n, target, result;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    result = iterativeBinarySearch(array, n, target);
    if (result != -1) {
        printf("Element found at index %d using iterative binary search.\n", result);
    } else {
        printf("Element not found using iterative binary search.\n");
    }

    result = recursiveBinarySearch(array, 0, n - 1, target);
    if (result != -1) {
        printf("Element found at index %d using recursive binary search.\n", result);
    } else {
        printf("Element not found using recursive binary search.\n");
    }

    return 0;
}

int iterativeBinarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int recursiveBinarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            return recursiveBinarySearch(arr, mid + 1, right, target);
        }

        return recursiveBinarySearch(arr, left, mid - 1, target);
    }

    return -1;
}
