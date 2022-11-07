#include<iostream>
#include<climits>
using namespace std;

int getMaxSubarraySum(int arr[], int n){
    int ans = INT_MIN;
    int sum = 0;
    
    for(int i = 0; i < n; i++){
        sum = sum + arr[i];
        
        ans = max(ans, sum);
        
        if(sum<0)
            sum = 0;
    }
    
    return ans;
}

int main()

{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    cout<<"Max subarray sum is : "<< getMaxSubarraySum(arr, 9);
    
    
    return 0;
}