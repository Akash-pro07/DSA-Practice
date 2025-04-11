#include<stdio.h>

void main()
{
    int a[100], i, key, n, flag = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            flag = 1;
            printf("Element found at %d\n", i);
        }
    }

    if(flag != 1)
    {
        printf("Element not found");
    }
}
