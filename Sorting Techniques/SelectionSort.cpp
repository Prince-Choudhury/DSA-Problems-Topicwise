#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int arr[] = {13, 18, 1, 5, 2, 8, 7, 4, 16, 3, 1};
    int n = 11;

    for (int i = 0; i < n; i++)
    {   
        int minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        
        swap(arr[i], arr[minIndex]);

        cout<<arr[i]<<" ";
    }
   
    return 0;
}