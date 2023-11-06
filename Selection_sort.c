#include<stdio.h>
int main()
{
    int n, t;

    printf("\nEnter the size of an array : ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the element for an array : --------------------\n");
    for (int i = 0 ; i < n ; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0 ; i < n -1 ; i++)
    {
        int min = i;

        for (int j = i + 1 ; j < n ; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            t = a[i];
            a[i] = a[min];
            a[min] = t;
        }
    }

    printf("\nAfter sorting -----------------\n");
    for (int i = 0 ; i < n ; i++)
    {
        printf("%d ", a[i]);
    }
}


/*

Best Case Time complexity = O(n^2)
Worst Case Time complexity = O(n^2)
Average Case Time complexity = O((n+1)/2)

*/

