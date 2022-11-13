#include<iostream>
#include<algorithm>
using namespace std;

int firstOcc(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;
    int mid = (start + end)/2;  

    int ans = -1;
    while (start<=end)
    { 
        int midElement = arr[mid];

        if (midElement == target){
            ans = mid;
            end = mid - 1;
        }
        else if(target<midElement)   
            end = mid - 1;

        else
            start = mid + 1;   

        mid = (start + end)/2;     

    }

    return ans;       
}



int LastOcc(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;
    
    int mid = start + (end - start)/2;  

    int ans = -1;
    while (start<=end)
    {
        int midElement = arr[mid];

        if(midElement == target){
            ans = mid;
            start = mid+1;
        }
            
        else if(target<midElement)   
            end = mid - 1;

        else
            start = mid + 1;    

        mid = start + (end - start)/2;    

    }

    return ans;       
}

int main()
{
    int arr[] = {3,4,5,5,5,5,8,12}; 
    int target = 5;
    int n = 8;

    cout<<"First Occurrence : "<<firstOcc(arr, n, target)<<endl;
    cout<<"Last Occurrence : "<<LastOcc(arr, n, target);


    return 0;
}