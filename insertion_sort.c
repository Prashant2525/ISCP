#include <stdio.h>

void insertion_sort(int a[], int n)
{
    int j, key;
    for (int i = 1 ; i < n ; i++)
    {
        key = a[i];
        j = i - 1;

        while (key < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        
    }
}

void display(int a[], int n)
{
    int j;
    for(j = 0 ; j < n ; j++)
    {
        printf("%d ", a[j]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("\nEnter no of elements : ");
    scanf("%d", &n);

    int a[n];
    printf("\nEnter the elements in an array ----- \n\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nBefore sorting : \n");
    display(a,n);

    insertion_sort(a,n);

    printf("\nAfter sorting : \n");
    display(a,n);
}


// void insertion_sort(int a[], int n)
// {
//     int j, key;
//     for (int i = 1 ; i < n ; i++)
//     {
//         key = a[i];
//         j = i - 1;

//         while (key < a[j] && j >= 0)
//         {
//             a[j + 1] = a[j];
//             j--;
//         }
//         a[j + 1] = key;
        
//     }
// }