#include <stdio.h>

int main() {
    int array1[100], array2[100], mergedArray[200];
    int n1, n2, i, j;

    printf("Enter number of elements in the first array: ");
    scanf("%d", &n1);

    printf("Enter %d elements for the first array: ", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &array1[i]);
    }

    printf("Enter number of elements in the second array: ");
    scanf("%d", &n2);

    printf("Enter %d elements for the second array: ", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &array2[i]);
    }

    for (i = 0; i < n1; i++) {
        mergedArray[i] = array1[i];
    }

    for (j = 0; j < n2; j++) {
        mergedArray[i + j] = array2[j];
    }

    printf("Merged array: ");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    return 0;
}
