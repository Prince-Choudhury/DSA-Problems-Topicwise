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
    int arr[]={2, 7, 5, 6, 9, 8, 0};

    SwapAlternatesArr(arr, 7);
    
    
    for (int i = 0; i <7; i++)
    {
        cout << arr[i] << ' ';
    }

    cout<<endl;

    return 0;
}
