#include <stdio.h>
#include <stdlib.h>  // For exit()

#define MAX_SIZE 5

void push(int data);
void pop();
void peek();
void display();

int stack[MAX_SIZE];
int top = -1;

int main()
{
    int choice, no;
    do
    {
        printf("\n1. Push  2. Pop  3. Peek  4. Display  5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &no);
                push(no);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(1);

    return 0;
}

void push(int data)
{
    if(top == MAX_SIZE - 1)
    {
        printf("Stack overflow!\n");
    }
    else
    {
        top++;
        stack[top] = data;
        printf("%d added to the stack.\n", data);
    }
}

void pop()
{
    if(top == -1)
    {
        printf("Stack underflow!\n");
    }
    else
    {
        printf("%d removed from the stack.\n", stack[top]);
        top--;
    }
}

void peek()
{
    if(top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }
}

void display()
{
    if(top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        int i;
        printf("Stack elements (top to bottom): ");
        for(i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
