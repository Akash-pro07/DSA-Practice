#include <stdio.h>

int a[20], size, f, r;

void Enqueue(int item) {
    if (r == size - 1) {
        printf("Queue is full!\n");
    } else if (r == -1) {
        f = 0;
        r = 0;
        a[r] = item;
        printf("%d inserted into the queue.\n", item);
    } else {
        r++;
        a[r] = item;
        printf("%d inserted into the queue.\n", item);
    }
}

void Dequeue() {
    if (f == -1) {
        printf("Queue is empty!\n");
    } else if (f == r) {
        printf("Deleted item is %d\n", a[f]);
        f = -1;
        r = -1;
    } else {
        printf("Deleted item is %d\n", a[f]);
        f++;
    }
}

void Display() {
    int i;
    if (f == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (i = f; i <= r; i++) {
            printf("%d\t", a[i]);
        }
        printf("\n");
    }
}

void main() {
    int item, opt;
    f = -1;
    r = -1;

    printf("Enter the size of queue: ");
    scanf("%d", &size);

    do {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                Enqueue(item);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (opt != 4);
}
