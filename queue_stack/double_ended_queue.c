#include <stdio.h>
#include <stdlib.h>

int deque[20];
int front = -1, rear = -1;

void insert_Front(int item, int size) {
    if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Double-ended queue is full!\n");
    } else if (front == -1) {
        front = rear = 0;
        deque[front] = item;
    } else if (front == 0) {
        front = size - 1;
        deque[front] = item;
    } else {
        front--;
        deque[front] = item;
    }
}

void insert_Rear(int item, int size) {
    if ((front == 0 && rear == size - 1) || (rear + 1 == front)) {
        printf("Double-ended queue is full!\n");
    } else if (rear == -1) {
        front = rear = 0;
        deque[rear] = item;
    } else if (rear == size - 1) {
        rear = 0;
        deque[rear] = item;
    } else {
        rear++;
        deque[rear] = item;
    }
}

int delete_Front(int size) {
    if (front == -1) {
        printf("Deque is empty! Unable to delete.\n");
        return -1;
    }
    int item = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }
    return item;
}

int delete_Rear(int size) {
    if (rear == -1) {
        printf("Deque is empty! Unable to delete.\n");
        return -1;
    }
    int item = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear--;
    }
    return item;
}

void display(int size) {
    if (front == -1) {
        printf("Double-ended queue is empty.\n");
        return;
    }
    printf("Double-ended queue elements are: ");
    int i = front;
    while (i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % size;
    }
    printf("%d\n", deque[rear]);
}

int main() {
    int size, choice, item;

    printf("Enter the size of the deque: ");
    scanf("%d", &size);

    while (1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. Enqueue Front\n2. Enqueue Rear\n3. Dequeue Front\n4. Dequeue Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue at front: ");
                scanf("%d", &item);
                insert_Front(item, size);
                break;
            case 2:
                printf("Enter element to enqueue at rear: ");
                scanf("%d", &item);
                insert_Rear(item, size);
                break;
            case 3:
                item = delete_Front(size);
                if (item != -1)
                    printf("Dequeued from front: %d\n", item);
                break;
            case 4:
                item = delete_Rear(size);
                if (item != -1)
                    printf("Dequeued from rear: %d\n", item);
                break;
            case 5:
                display(size);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
