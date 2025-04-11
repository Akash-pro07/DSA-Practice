#include <stdio.h>

void insertionSort(int n, int a[])
{
    int i, j, item;
    for(i = 1; i < n; i++)
    {
        item = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > item)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = item;
    }

    printf("Sorted Array is:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void main()
{
    int n, a[50], i;

    printf("Enter the limit: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
    }

    insertionSort(n, a);
}
