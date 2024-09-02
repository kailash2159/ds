#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert() {
    if (rear == MAX - 1) {
        printf("Queue is full. Cannot insert.\n");
        return;
    }

    int value;
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    if (front == -1) front = 0;

    queue[++rear] = value;
    printf("Inserted %d into the queue.\n", value);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }

    printf("Deleted %d from the queue.\n", queue[front++]);

    if (front > rear) {
        front = rear = -1;  // Reset the queue when all elements are deleted
    }
}

void traversal() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void peep() {
    if (front == -1) {
        printf("Queue is empty. Nothing to peep.\n");
        return;
    }
    printf("Front element is: %d\n", queue[front]);
}

void isFull() {
    if (rear == MAX - 1) {
        printf("Queue is full.\n");
    } else {
        printf("Queue is not full.\n");
    }
}

void isEmpty() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. TRAVERSAL\n");
        printf("4. PEEP\n");
        printf("5. ISFULL\n");
        printf("6. ISEMPTY\n");
        printf("7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: traversal(); break;
            case 4: peep(); break;
            case 5: isFull(); break;
            case 6: isEmpty(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
