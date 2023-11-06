// #include<iostream>
// using namespace std;

// int main()
// {
//     int n, a;

//     cout<<"Enter the coeff: ";
//     cin>>a;
//     cout<<"Enter the power: ";
//     cin>>n;
//     int arr[n];

//     for (int i = 0 ; i < n ; i++)
//     {
//         arr[i] = a;
//     }

      
// }

#include<iostream>
using namespace std;

int power(int base, int expo)
{
    if (expo == 0)
    {
        return 1; // Base case: a^0 is 1   
    }
    else
    {
        int temp = power(base, expo - 1); // Recursive call with b decremented
        // cout<<temp<<endl;
        return base * temp;
    }
}
int main()
{
    int base = 5;
    int expo = 3;

    cout<<power(base,expo);
}