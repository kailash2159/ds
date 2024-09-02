#include <stdio.h>

int main() {
    int array[100], position, i, n;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the position of the element to be deleted: ");
    scanf("%d", &position);

    if (position >= n+1 || position <= 0) {
        printf("Invalid position! Please enter a position between 1 and %d\n", n);
    } else {
        for (i = position - 1; i < n - 1; i++) {
            array[i] = array[i + 1];
        }

        n--;

        printf("Array after deletion: ");
        for (i = 0; i < n; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    return 0;
}
