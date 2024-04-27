// Find (value = index) in a sorted array

#include<iostream>
#include<algorithm>
using namespace std;


int fixedPoint(int arr[], int n)
{
    int start = 0;
    int end = n-1;
    
    int mid = start + (end - start)/2;   

    while (start<=end)
    {
        int midElement = arr[mid];

        if(midElement == mid){
            return mid;
        }
            
        else if(mid<midElement)   
            end = mid - 1;
            
        else
            start = mid + 1;    

        mid = start + (end - start)/2;     

    }

    return -1;       
}

int main()
{
    int arr[] = {-10, -5, 0, 3, 7}; 
    int n = 5;

    cout<<fixedPoint(arr, n);

    return 0;
}