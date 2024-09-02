#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int element;
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue is Full.\n");
    } else {
        printf("Enter the element to insert: ");
        scanf("%d", &element);
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = element;
    }
}

void delete() {
    if (front == -1) {
        printf("Queue is Empty.\n");
    } else {
        printf("Deleted element is: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty.\n");
    } else {
        printf("Queue elements are: ");
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                printf("%d ", queue[i]);
        } else {
            for (int i = front; i < MAX; i++)
                printf("%d ", queue[i]);
            for (int i = 0; i <= rear; i++)
                printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peep() {
    if (front == -1) {
        printf("Queue is Empty.\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

void isFull() {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue is Full.\n");
    } else {
        printf("Queue is not Full.\n");
    }
}

void isEmpty() {
    if (front == -1) {
        printf("Queue is Empty.\n");
    } else {
        printf("Queue is not Empty.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. INSERT\n2. DELETE\n3. DISPLAY\n4. PEEP\n5. ISFULL\n6. ISEMPTY\n7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                peep();
                break;
            case 5:
                isFull();
                break;
            case 6:
                isEmpty();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
