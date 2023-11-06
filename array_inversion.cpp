#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int n, count = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // for (int i = 0 ; i < n ; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }

    cout << count;
}