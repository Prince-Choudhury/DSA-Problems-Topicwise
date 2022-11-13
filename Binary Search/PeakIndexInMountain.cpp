#include<iostream>
#include<algorithm>
using namespace std;

int getPeak(int arr[], int n){
    int start = 0;
    int end = n-1;

    int mid = start + (end - start)/2;

    while (start < end)
    {
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        
        else
            end = mid;

        mid = start + (end - start)/2;     
    }
    
    return start;

}

int main()
{
    int arr[] = {3,4,5,1};
    
    cout<<"Peak index : "<<getPeak(arr, 4);


    return 0;
}