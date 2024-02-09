// Find intersection of two sorted arrays
// There should be no duplicate element present in the sorted arrays

#include <iostream>
using namespace std;

void printInersection(int arr1[], int arr2[], int n, int m)
{

    int i = 0;
    int j = 0;

     while (i < n && j < m)
    {
        if (arr1[i] == arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) 
            i++;
        else
            j++;
    }
}

int main()
{
    int arr1[] = {2, 3, 5, 7};
    int arr2[] = {3, 4, 5, 6, 7};

    printInersection(arr1, arr2, 4, 5);

    return 0;
}