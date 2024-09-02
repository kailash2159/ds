#include <stdio.h>

int main() {
    int array1[100], array2[100], mergedArray[200];
    int n1, n2, i = 0, j = 0, k = 0;

    printf("Enter number of elements in the first sorted array: ");
    scanf("%d", &n1);

    printf("Enter %d sorted elements for the first array: ", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &array1[i]);
    }

    printf("Enter number of elements in the second sorted array: ");
    scanf("%d", &n2);

    printf("Enter %d sorted elements for the second array: ", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &array2[i]);
    }

    i = 0;
    j = 0;

    while (i < n1 && j < n2) {
        if (array1[i] < array2[j]) {
            mergedArray[k++] = array1[i++];
        } else {
            mergedArray[k++] = array2[j++];
        }
    }

    while (i < n1) {
        mergedArray[k++] = array1[i++];
    }

    while (j < n2) {
        mergedArray[k++] = array2[j++];
    }

    printf("Merged sorted array: ");
    for (i = 0; i < k; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    return 0;
}
