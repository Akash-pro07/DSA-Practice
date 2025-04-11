#include <stdio.h>

void main()
{
    int a[100], n, i, j, temp, small;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        small = i;
        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[small])
            {
                temp = a[small];
                a[small] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nSorted array is:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
