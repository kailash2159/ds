#include <stdio.h>

void insertElement(int arr[], int *n, int element, int position) {
    if (position < 0 || position > *n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;

    (*n)++;
}

int main() {
    int n, element, position;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n + 1];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert the element (0 to %d): ", n);
    scanf("%d", &position);

    insertElement(arr, &n, element, position);

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
