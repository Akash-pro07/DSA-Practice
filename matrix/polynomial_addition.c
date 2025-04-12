#include <stdio.h>

struct polynomial {
    int e; // exponent
    int c; // coefficient
};

struct polynomial p[25], q[25], r[25];

void main() {
    int m, n, i, j, k, z;

    printf("Please enter the elements in the decreasing order\n");

    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        printf("Enter coefficient: ");
        scanf("%d", &p[i].c);
        printf("Enter exponent: ");
        scanf("%d", &p[i].e);
    }

    printf("\nFirst polynomial is: ");
    for(i = 0; i < m; i++) {
        printf("%dx^%d", p[i].c, p[i].e);
        if(i < m - 1)
            printf(" + ");
    }

    printf("\n\nEnter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter coefficient: ");
        scanf("%d", &q[i].c);
        printf("Enter exponent: ");
        scanf("%d", &q[i].e);
    }

    printf("\nSecond polynomial is: ");
    for(i = 0; i < n; i++) {
        printf("%dx^%d", q[i].c, q[i].e);
        if(i < n - 1)
            printf(" + ");
    }

    i = j = k = 0;
    while(i < m && j < n) {
        if(p[i].e == q[j].e) {
            r[k].c = p[i].c + q[j].c;
            r[k].e = p[i].e;
            i++; j++; k++;
        } else if(p[i].e > q[j].e) {
            r[k] = p[i];
            i++; k++;
        } else {
            r[k] = q[j];
            j++; k++;
        }
    }

    while(i < m) {
        r[k] = p[i];
        i++; k++;
    }

    while(j < n) {
        r[k] = q[j];
        j++; k++;
    }

    z = k;

    printf("\n\nThe resultant polynomial is: ");
    for(k = 0; k < z; k++) {
        printf("%dx^%d", r[k].c, r[k].e);
        if(k < z - 1)
            printf(" + ");
    }

    printf("\n");
}
