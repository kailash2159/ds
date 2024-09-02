#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *str) {
    if (top < MAX - 1) {
        strcpy(stack[++top], str);
    } else {
        printf("Stack Overflow\n");
    }
}

char *pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return NULL;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void postfixToInfix(char *postfix) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        
        if (isalnum(ch)) {
            char operand[2] = {ch, '\0'};
            push(operand);
        }
        else if (isOperator(ch)) {
            char op2[MAX], op1[MAX];
            strcpy(op2, pop());
            strcpy(op1, pop());

            char expression[MAX] = "(";
            strcat(expression, op1);
            strcat(expression, &ch);  
            strcat(expression, op2);
            strcat(expression, ")");

            push(expression);
        }
    }

    printf("Infix expression: %s\n", pop());
}

int main() {
    char postfix[MAX];
    
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    postfixToInfix(postfix);

    return 0;
}

