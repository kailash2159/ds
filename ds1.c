#include <stdio.h>

int main() {
    int n, i, search, array[100];

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the value to find: ");
    scanf("%d", &search);

    for (i = 0; i < n; i++) {
        if (array[i] == search) {
            printf("%d is present at location %d.\n", search, i+1);
            break;
        }
    }

    if (i == n) {
        printf("%d is not present in the array.\n", search);
    }

    return 0;
}
