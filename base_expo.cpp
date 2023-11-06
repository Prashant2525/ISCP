// #include<iostream>
// using namespace std;
// int main()
// {
//     int base;
//     int expo;
//     int final = 1;
//     cout<<"Enter the base value: ";
//     cin>>base;
//     cout<<"Enter the expo value: ";
//     cin>>expo;

//     for (int i = 1 ; i <= expo ; i++)
//     {
//         cout<<base<<"^"<<i;
//         if(i < expo)
//         {
//             cout<<", ";
//         }
//     }
//     cout<<endl;
//     while (expo > 0)
//     {
//         final *= base;
//         expo--;
//     }

//     cout<<"Answer: "<<final;

// }

#include <iostream>
using namespace std;

int power(int base, int expo)
{
    if (expo == 0)
    {
        return 1;
    }
    else
    {
        int temp = power(base, expo - 1);
        cout << temp << endl;
        return base * temp;
    }
}
int main()
{
    int base = 5;
    int expo = 3;

    cout << power(base, expo);
}


#include <iostream>
using namespace std;
long power(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        long temp = power(a, n / 2);
        return temp * temp;
    }
    else
    {
        long temp = power(a, (n - 1) / 2);
        return a * temp * temp;
    }
}

int main()
{
    int a, n;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << a << "^" << n << " = " << power(a, n) << endl;
    return 0;
}