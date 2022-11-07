// Check wether an array is palindrome or not

#include<iostream>
using namespace std;

bool palindromOrNot(int arr[], int n){

    int i = 0;
    int j = n-1;

    while (i < j)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else
            return false;

    }

    return true;
}

int main()
{
    int arr[30];
    int n;
    cout<<"Enter Array size : ";
    cin>>n;
    cout<<"Enter array elements : "<<endl;

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Palindrom or not : "<<palindromOrNot(arr, n);

    return 0;
}
