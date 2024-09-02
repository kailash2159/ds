#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

typedef struct {
    int items[MAX];
    int top;
} Stack;

void push(Stack* s, int value);
int pop(Stack* s);
int peep(Stack* s);
void display(Stack* s);
int isFull(Stack* s);
int isEmpty(Stack* s);

int main() {
    Stack s;
    s.top = -1;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Display\n");
        printf("5. IsFull\n");
        printf("6. IsEmpty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peep(&s);
                if (value != -1) {
                    printf("Top value: %d\n", value);
                }
                break;
            case 4:
                display(&s);
                break;
            case 5:
                if (isFull(&s)) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
            case 6:
                if (isEmpty(&s)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push more elements.\n");
    } else {
        s->top++;
        s->items[s->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop elements.\n");
        return -1;
    } else {
        return s->items[s->top--];
    }
}

int peep(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}
