#include <stdio.h>
#include <stdlib.h>

int circularQueue[20];
int front = -1, rear = -1;

int isFull(int size) {
    return ((rear == size - 1 && front == 0) || (rear + 1 == front));
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int item, int size) {
    if (isFull(size)) {
        printf("Circular Queue is full!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == size - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    circularQueue[rear] = item;
    printf("Enqueued element: %d\n", item);
}

int dequeue(int size) {
    if (isEmpty()) {
        printf("Circular Queue is empty!\n");
        return -1;
    }
    int item = circularQueue[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }
    return item;
}

void display(int size) {
    if (isEmpty()) {
        printf("Circular Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements are: ");
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", circularQueue[i]);
        }
    } else {
        for (int i = front; i < size; i++) {
            printf("%d ", circularQueue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", circularQueue[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, item, size;

    printf("Enter the size of the Circular Queue: ");
    scanf("%d", &size);

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item, size);
                break;
            case 2:
                item = dequeue(size);
                if (item != -1) {
                    printf("Dequeued element: %d\n", item);
                }
                break;
            case 3:
                display(size);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}
