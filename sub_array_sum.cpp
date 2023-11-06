#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Size: ";
    cin>>n;
    int a[n];
    int t = 13;
    cout<<"\nEnter the number: "<<endl;
    for (int i = 0 ; i < n ; i++)
    {
        cin>>a[i];
    }

    for (int i = 0 ; i < n ; i++)
    {
        for (int j = i + 1 ; j < n ; j++)
        {
            for (int k = j + 1 ; k < n ; k++)
            {
                for (int s = k + 1 ; s < n ; s++)
                {
                    if(a[i] + a[j] + a[k] + a[s] == t)
                    {
                        cout<<"Sub array that sum "<<t<<" is: ["<<a[i]<<", "<<a[j]<<", "<<a[k]<<", "<<a[s]<<"]"<<endl;
                    }
                }
            }
        }
    }
}