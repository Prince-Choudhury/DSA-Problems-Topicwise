#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int binarySearch(int arr[], int s, int e, int target){

    while (s<=e)
    {
        int mid = s + (e-s)/2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] > target)
        {
            e = mid - 1;
        }
        else
            s = mid + 1;
        }

    return -1;
    
}

//we dont know the size of array, 
// considering it infinite as per question
//assumption array size if infinite, so no Index Out of Bound Exception
int findPosition(int arr[], int target){
    int s = 0, e = 1;
    int value = arr[s];

    while (value < target)
    {
        s = e;
        e = 2*e;
        value = arr[e];
    }
    
    return binarySearch(arr, s, e, target);

}

int main()
{
    int arr[] = {3,7,13,18,24,30,34,37,40};
    int target = 30;

    cout<<findPosition(arr, target);

    return 0;
}