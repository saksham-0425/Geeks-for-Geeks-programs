#include <stdio.h>
#include <stdlib.h>

// Ques- Merge Sort :-

void merge(int arr[], int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    int b[h + 1];

    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = arr[i];
        k++;
        i++;
    }
    while (j <= h)
    {
        b[k] = arr[j];
        k++;
        j++;
    }
    for(int p=l;p<=h;p++){
        arr[p]=b[p];
    }
}

void printarray(int arr[],int n){
    printf("array elements : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}

void mergesort(int arr[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
    
}

int main()
{
    int n;
    printf("size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("enter array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int l, h;
    l = 0;
    h = n - 1;
    mergesort(arr, l, h);
    printarray(arr,n);

   
}