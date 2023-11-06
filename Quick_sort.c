#include <stdio.h>

int partation(int a[], int lb, int ub)
{
    int pivort = a[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (a[start] <= pivort)
        {
            start++;
        }
        while (a[end] > pivort)
        {
            end--;
        }
        if (start < end)
        {
            int t = a[start];
            a[start] = a[end];
            a[end] = t;
        }
    }
    int t = a[lb];
    a[lb] = a[end];
    a[end] = t;
    return end;
}

void quick_sort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partation(a, lb, ub);
        quick_sort(a, lb, loc - 1);
        quick_sort(a, loc + 1, ub);
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

    quick_sort(a, 0, n - 1);

    printf("\nAfter Sorting : ");
    print(a, n);
}
