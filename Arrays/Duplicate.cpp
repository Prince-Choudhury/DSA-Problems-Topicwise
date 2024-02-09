// Find Duplicate in an array of (N+1) integer

#include <iostream>
using namespace std;

int DuplicateNo(int arr[], int n){
    int sum1 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 = sum1 + arr[i];
    }
    int m = n - 1;
    int sum2 = (m*(m+1))/2;
    int ans = sum1 - sum2;

    return ans;
    
}

int main()
{

    int arr[] = {1,2,3,3,4};
    cout<<DuplicateNo(arr, 5);

    return 0;
}