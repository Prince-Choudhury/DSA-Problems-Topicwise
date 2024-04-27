#include<iostream>
#include<algorithm>
using namespace std;


int firstOcc(int arr[], int n, int target)
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
            end = mid-1;
        }
            
        else if(target<midElement)   
            end = mid - 1;
            
        else
            start = mid + 1;    

        mid = start + (end - start)/2;     

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
            
        if(target<midElement)   
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

    int ans1 = firstOcc(arr, n, target);
    int ans2 = LastOcc(arr, n, target);
    int ans = ans2 - ans1 + 1;
    cout<<"Total no of Occurrence : "<<ans;

    return 0;
}