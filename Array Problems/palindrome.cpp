#include<iostream>
using namespace std;


int main()
{
    int arr[10] = {2, 3, 8, 5, 10};
    int n = 5;
    int i = 0;
    int j = n - 1;
    while (i<j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    
    
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;

    
    return 0;
}
