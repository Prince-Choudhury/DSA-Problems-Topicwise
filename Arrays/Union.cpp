// Find union of two sorted arrays
// There should be no duplicate element present in the sorted arrays

#include <iostream>
using namespace std;

void printUnion(int arr1[], int arr2[], int n, int m)
{

    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] > arr2[j])
            cout << arr2[j++] << " "; // cout<<arr2[j++] is equivalent to cout<<arr2[j],  j++

        else if (arr1[i] < arr2[j]) // cout<<arr1[i],  i++
            cout << arr1[i++] << " ";
        else
            cout << arr2[j++] << " "; // cout<<arr2[j],  j++
        i++;
    }

    // Print remaining elements of the larger array

    while (i < n)
    {
        cout << arr1[i++] << " ";
    }

    while (j < m)
    {
        cout << arr2[j++] << " ";
    }
}

int main()
{
    int arr1[] = {2, 3, 5, 7};
    int arr2[] = {3, 4, 5, 6, 7};

    printUnion(arr1, arr2, 4, 5);

    return 0;
}



