#include <iostream>
#include <limits.h>
using namespace std;

void SwapAlternatesArr(int arr[], int n){
    int i = 0;
    while (i < n)
    {
        if (i + 1 < n){
            swap(arr[i], arr[i + 1]);
        }

        i = i + 2;
    }
 
}


int main()
{
    int arr[]={3, 24, 53, 2, 22, 98};

    SwapAlternatesArr(arr, 6);
    
    
    for (int i = 0; i <6; i++)
    {
        cout << arr[i] << ' ';
    }

    cout<<endl;

    return 0;
}
