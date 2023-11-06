#include <iostream>
using namespace std;
int main()
{
    int a[100];
    int n, key, address;
    int count = 0, found = 0;
    cout << "Enter the number of items: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value for a[" << i + 1 << "]: ";
        cin >> a[i];
    }

    cout << "Which numeber you want to search: ";
    cin >> key;

    for (int j = 0; j < n; j++)
    {
        if (a[j] == key)
        {
            found = 1;
            address = j + 1;
            break;
        }
    }
    // cout << "Total number of " << key << " is" : << count;
    if(found == 1)
    {
        cout<<"Address of first 1 in an array is: "<<address;
    }
}