#include <stdio.h>
#include <stdlib.h>

int F = -1, R = -1, pq[5], i;
int capacity = 5;

void insertionSort(int item) {
    int j;
    for (j = R; j >= F && item < pq[j]; j--) {
        pq[j + 1] = pq[j];
    }
    pq[j + 1] = item;
    R++;
}

void Enqueue() {
    int item;
    if (R == capacity - 1) {
        printf("Queue is full.\n");
    } else {
        printf("Enter the element to enqueue: ");
        scanf("%d", &item);
        if (F == -1) {
            F = R = 0;
            pq[R] = item;
        } else {
            insertionSort(item);
        }
        printf("Enqueued: %d\n", item);
    }
}

void Dequeue() {
    if (F == -1) {
        printf("Queue is empty.\n");
    } else {
        int removed = pq[F];
        if (F == R) {
            F = R = -1;
        } else {
            F++;
        }
        printf("Removed element is: %d\n", removed);
    }
}

void Display() {
    if (F == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Priority Queue: ");
        for (i = F; i <= R; i++) {
            printf("%d ", pq[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
