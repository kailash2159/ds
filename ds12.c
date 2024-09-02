#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 10

// Stack to hold the operands
int stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        // If the character is an operand, push it onto the stack
        if (isdigit(exp[i])) {
            push(exp[i] - '0');  // Convert character to integer
        }
        // If the character is an operator, pop two elements, apply the operator, and push the result
        else {
            int val1 = pop();
            int val2 = pop();
            switch (exp[i]) {
                case '+':
                    push(val2 + val1);
                    break;
                case '-':
                    push(val2 - val1);
                    break;
                case '*':
                    push(val2 * val1);
                    break;
                case '/':
                    push(val2 / val1);
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", exp[i]);
                    exit(1);
            }
        }
    }
    // The result will be on the top of the stack
    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter a postfix expression: ");
    gets(exp);

    int result = evaluatePostfix(exp);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
