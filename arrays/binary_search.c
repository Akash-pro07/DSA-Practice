#include <stdio.h>

void main()
{
    int a[100], i, key, l = 0, r, n, m, flag = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    r = n - 1;

    for(i = 0; i < n; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    while(l <= r)
    {
        m = (l + r) / 2;

        if(a[m] == key)
        {
            flag = 1;
            break;
        }
        else if(a[m] < key)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    if(flag == 1)
    {
        printf("Element is found at %d", m);
    }
    else
    {
        printf("Element not found");
    }
}
