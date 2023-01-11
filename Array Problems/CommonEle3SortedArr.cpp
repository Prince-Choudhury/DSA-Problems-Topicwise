#include <iostream>
using namespace std;

void printInersection(int arr1[], int arr2[], int arr3[], int n, int m, int p)
{

    int i = 0;
    int j = 0;
    int ans[30];

     while (i < n && j < m)
    {
        if (arr1[i] == arr2[j]){
            ans[30] = arr1[i];
            
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
    int arr3[] = {5, 7, 9, 12, 15, 19};

    printInersection(arr1, arr2, arr3, 4, 5, 6);

    return 0;
}