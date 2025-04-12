#include<stdio.h>
#include<stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

void readPolynomial(struct Node** poly) {
    int coeff, pow, cont;
    struct Node *temp, *tail = NULL;

    do {
        printf("\nCoefficient: ");
        scanf("%d", &coeff);
        printf("Exponent: ");
        scanf("%d", &pow);

        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->coeff = coeff;
        temp->pow = pow;
        temp->next = NULL;

        if (*poly == NULL) {
            *poly = temp;
        } else {
            tail->next = temp;
        }
        tail = temp;

        printf("Have more terms? (1 for yes / 0 for no): ");
        scanf("%d", &cont);
    } while (cont);
}

void displayPolynomial(struct Node* poly) {
    printf("\nPolynomial expression is: ");
    while (poly != NULL) {
        printf("%dX^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

void addPolynomials(struct Node** result, struct Node* first, struct Node* second) {
    struct Node *temp = NULL, *tail = NULL;

    while (first && second) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next = NULL;

        if (first->pow > second->pow) {
            newNode->coeff = first->coeff;
            newNode->pow = first->pow;
            first = first->next;
        } else if (first->pow < second->pow) {
            newNode->coeff = second->coeff;
            newNode->pow = second->pow;
            second = second->next;
        } else {
            newNode->coeff = first->coeff + second->coeff;
            newNode->pow = first->pow;
            first = first->next;
            second = second->next;
        }

        if (*result == NULL) {
            *result = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    while (first) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = first->coeff;
        newNode->pow = first->pow;
        newNode->next = NULL;

        if (*result == NULL) {
            *result = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        first = first->next;
    }

    while (second) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->coeff = second->coeff;
        newNode->pow = second->pow;
        newNode->next = NULL;

        if (*result == NULL) {
            *result = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        second = second->next;
    }
}

int main() {
    struct Node *first = NULL, *second = NULL, *result = NULL;

    printf("Enter first polynomial:\n");
    readPolynomial(&first);
    displayPolynomial(first);

    printf("Enter second polynomial:\n");
    readPolynomial(&second);
    displayPolynomial(second);

    addPolynomials(&result, first, second);

    printf("\nResultant Polynomial after addition:\n");
    displayPolynomial(result);

    return 0;
}
