#include <stdio.h>

void merge(int a[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    int temp[50];

    while(i <= mid && j <= right)
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= right)
        temp[k++] = a[j++];

    for(i = left, j = 0; i <= right; i++, j++)
        a[i] = temp[j];
}

void mergesort(int a[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    int a[50], n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
    }

    mergesort(a, 0, n - 1);

    printf("The sorted array is: ");
    for(i = 0; i < n; i++)
        printf("%d\t", a[i]);

    return 0;
}
