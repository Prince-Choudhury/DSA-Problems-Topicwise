#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


bool isPrime(int n){

    if (n<=1)
    {
        return false;
    }
    
   for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cout<<"Enter your number : ";
    cin>>n;
    cout<<"Prime or Not : "<<isPrime(n);

    return 0;
}