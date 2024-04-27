//Move Negative no to one side of Array

#include <iostream>
using namespace std;

/*
int main()
{
    int arr[] = {3, -1, 2, -4, -6, -4, 5};
    int n = 7;
    int i = 0;
    int j = 0;

    while(i<n)
    {
        if (arr[i] < 0)
        {
            cout<<arr[i]<<" ";
        }
        i++;
    }

    while(j<n)
    {
        if (arr[j] > 0)
        {
            cout<<arr[j]<<" ";
        }
        j++;
    }
    

    return 0;
}
*/


void NegNoOneSide(int arr[], int n){
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
    
}

int main()
{
    int arr[] = {3, -1, 2, -4, -6, -4, 5};
    int n = 7;

    NegNoOneSide(arr, 7);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}