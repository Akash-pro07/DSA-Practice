#include <stdio.h>

void main()
{
    int a[20][20], b[20][3], t[20][3];
    int i, j, r, c, count = 0, k = 1;

    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("Enter the element: ");
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nGiven Matrix:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Creating sparse matrix
    b[0][0] = r;
    b[0][1] = c;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
                count++;
            }
        }
    }

    b[0][2] = count;

    printf("\nSparse Matrix:\n");
    for(i = 0; i < k; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

    // Transpose of sparse matrix stored in t
    t[0][0] = b[0][1];
    t[0][1] = b[0][0];
    t[0][2] = b[0][2];

    for(i = 1; i < k; i++)
    {
        t[i][0] = b[i][1];
        t[i][1] = b[i][0];
        t[i][2] = b[i][2];
    }

    printf("\nTranspose Matrix (in sparse form):\n");
    for(i = 0; i < k; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d\t", t[i][j]);
        }
        printf("\n");
    }
}
