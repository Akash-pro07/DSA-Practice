#include <stdio.h>

int partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int i = left;
    int j = right;
    int temp;

    while(i <= j)
    {
        while(arr[i] <= pivot && i <= right)
            i++;
        while(arr[j] > pivot)
            j--;

        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;

    return j;
}

void quicksort(int arr[], int left, int right)
{
    if(left < right)
    {
        int q = partition(arr, left, right);
        quicksort(arr, left, q - 1);
        quicksort(arr, q + 1, right);
    }
}

int main()
{
    int arr[50], n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the array element: ");
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("The array after sorting is:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}
