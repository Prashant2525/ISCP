#include<stdio.h>

void merge(int a[], int lb, int mid, int ub)
{
    int b[ub + 1];
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub)
    {
        if(a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    if(i > mid)
    {
        while (j <= ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (int s = lb ; s <= ub  ; s++)
    {
        a[s] = b[s];
    }
    
}

void merge_sort(int a[], int lb, int ub)
{
    if(lb < ub)
    {
        int mid = (lb + ub) / 2;
        merge_sort(a, lb, mid);
        merge_sort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}



void print(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n, t;

    printf("\nEnter the size of an array : ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the element for an array : --------------------\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nBefore Sorting : ");
    print(a, n);

    merge_sort(a, 0, n - 1);

    printf("\nAfter Sorting : ");
    print(a, n);
}

