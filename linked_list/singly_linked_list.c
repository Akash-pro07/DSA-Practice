#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *Next;
};

struct node *Head = NULL;

struct node *createNode() {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter the data to insert: ");
    scanf("%d", &temp->data);
    temp->Next = NULL;
    return temp;
}

void insertAtHead() {
    struct node *temp = createNode();
    if (Head == NULL) {
        Head = temp;
    } else {
        temp->Next = Head;
        Head = temp;
    }
}

void insertAtTail() {
    struct node *temp = createNode();
    if (Head == NULL) {
        Head = temp;
    } else {
        struct node *ptr = Head;
        while (ptr->Next != NULL) {
            ptr = ptr->Next;
        }
        ptr->Next = temp;
    }
}

void insertAtSpecifiedPosition() {
    printf("Enter the position to insert: ");
    int pos;
    scanf("%d", &pos);
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insertAtHead();
        return;
    }
    struct node *ptr = Head;
    int i = 1;
    while (i < pos - 1 && ptr != NULL) {
        ptr = ptr->Next;
        i++;
    }
    if (ptr == NULL) {
        printf("Invalid position\n");
        return;
    }
    struct node *temp = createNode();
    temp->Next = ptr->Next;
    ptr->Next = temp;
}

void deleteAtHead() {
    if (Head == NULL) {
        printf("List is empty\n");
        return;
    } else {
        struct node *ptr = Head;
        Head = Head->Next;
        free(ptr);
    }
}

void deleteAtTail() {
    if (Head == NULL) {
        printf("List is empty\n");
        return;
    } else {
        struct node *ptr = Head;
        struct node *ptr2 = NULL;
        while (ptr->Next != NULL) {
            ptr2 = ptr;
            ptr = ptr->Next;
        }
        if (ptr == Head) {
            Head = NULL;
        } else {
            ptr2->Next = NULL;
        }
        free(ptr);
    }
}

void deleteAtPosition() {
    printf("Enter the position to delete: ");
    int pos;
    scanf("%d", &pos);
    if (Head == NULL || pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        deleteAtHead();
        return;
    }
    struct node *ptr = Head;
    struct node *ptr2 = NULL;
    int i = 1;
    while (i < pos && ptr != NULL) {
        ptr2 = ptr;
        ptr = ptr->Next;
        i++;
    }
    if (ptr == NULL) {
        printf("Invalid position\n");
        return;
    }
    ptr2->Next = ptr->Next;
    free(ptr);
}

void traverse() {
    struct node *ptr = Head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->Next;
    }
    printf("\n");
}

int main() {
    int op;
    printf("\t MENU \n");
    printf("1) Enter element from Head\n2) Enter element from tail\n3) Enter the element from specified position\n4) Remove element from Head\n5) Remove element from tail\n6) Remove element from specified position\n7) Display the list\n8) Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                insertAtHead();
                break;
            case 2:
                insertAtTail();
                break;
            case 3:
                insertAtSpecifiedPosition();
                break;
            case 4:
                deleteAtHead();
                break;
            case 5:
                deleteAtTail();
                break;
            case 6:
                deleteAtPosition();
                break;
            case 7:
                traverse();
                break;
            case 8:
                exit(0);
            default:
                printf("Choice not found!\n");
                break;
        }
    }
    return 0;
}
