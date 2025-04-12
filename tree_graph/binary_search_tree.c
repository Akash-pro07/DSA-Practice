#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* findMin(struct node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void insertNodeRecursive(struct node** current, int data) {
    if (*current == NULL) {
        *current = createNode(data);
    } else if (data <= (*current)->data) {
        insertNodeRecursive(&(*current)->left, data);
    } else {
        insertNodeRecursive(&(*current)->right, data);
    }
}

void inorderTraversal(struct node* node) {
    if (node == NULL) {
        return;
    }
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

void deleteTree(struct node* node) {
    if (node == NULL)
        return;
    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
}

int main() {
    int choice, data;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNodeRecursive(&root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Binary tree: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                deleteTree(root);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
