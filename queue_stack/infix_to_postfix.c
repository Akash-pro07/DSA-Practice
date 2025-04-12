#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0; // fallback
}

int main() {
    char exp[100], *e, x;
    
    printf("Enter the infix expression: ");
    scanf("%s", exp);
    
    printf("Postfix expression: ");

    e = exp;
    while (*e != '\0') {
        if (isalnum(*e)) {
            // Operand: output it directly
            printf("%c ", *e);
        }
        else if (*e == '(') {
            push(*e);
        }
        else if (*e == ')') {
            // Pop till '('
            while ((x = pop()) != '(')
                printf("%c ", x);
        }
        else {
            // Operator: pop operators with higher or equal precedence
            while (priority(stack[top]) >= priority(*e))
                printf("%c ", pop());
            push(*e);
        }
        e++;
    }

    // Pop remaining operators
    while (top != -1)
        printf("%c ", pop());

    printf("\n");
    return 0;
}
