#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** poly, int coefficient, int exponent) {
    // Skip zero coefficients
    if (coefficient == 0) return;

    struct Node* current = *poly;
    struct Node* prev = NULL;

    // Traverse the list and find the correct position for insertion
    while (current != NULL && current->exponent > exponent) {
        prev = current;
        current = current->next;
    }

    // If the term with the same exponent exists, add coefficients
    if (current != NULL && current->exponent == exponent) {
        current->coefficient += coefficient;
        // Remove the term if its coefficient becomes zero
        if (current->coefficient == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                *poly = current->next;
            }
            free(current);
        }
        return;
    }

    // Otherwise, insert a new term
    struct Node* newNode = createNode(coefficient, exponent);
    if (prev == NULL) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 == NULL) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else {
            if (poly1->exponent > poly2->exponent) {
                insertTerm(&result, poly1->coefficient, poly1->exponent);
                poly1 = poly1->next;
            } else if (poly1->exponent < poly2->exponent) {
                insertTerm(&result, poly2->coefficient, poly2->exponent);
                poly2 = poly2->next;
            } else {
                insertTerm(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
    }

    return result;
}

struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL) {
        struct Node* termResult = NULL;
        struct Node* temp2 = poly2;

        while (temp2 != NULL) {
            int coeff = poly1->coefficient * temp2->coefficient;
            int exp = poly1->exponent + temp2->exponent;

            insertTerm(&termResult, coeff, exp);
            temp2 = temp2->next;
        }

        result = addPolynomials(result, termResult);  // Reusing the polynomial addition function
        freePolynomial(termResult);
        poly1 = poly1->next;
    }

    return result;
}

void displayPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void freePolynomial(struct Node* poly) {
    struct Node* temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    int numTerms, coefficient, exponent;

    printf("Enter the number of terms for Polynomial 1: ");
    scanf("%d", &numTerms);

    printf("Enter the coefficients and exponents for Polynomial 1:\n");
    for (int i = 0; i < numTerms; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);
    }

    printf("\nEnter the number of terms for Polynomial 2: ");
    scanf("%d", &numTerms);

    printf("Enter the coefficients and exponents for Polynomial 2:\n");
    for (int i = 0; i < numTerms; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);
    }

    printf("\nPolynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Node* result = multiplyPolynomials(poly1, poly2);

    printf("Product: ");
    displayPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
