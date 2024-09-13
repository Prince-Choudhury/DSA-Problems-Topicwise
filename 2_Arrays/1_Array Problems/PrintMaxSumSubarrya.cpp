#include<iostream>
#include<climits>
using namespace std;

int getMaxSubarraySum(int arr[], int n){
    int ans = INT_MIN;
    int sum = 0;
    
    int start = 0, end = 0, tempStart = 0; // To track the indices of the subarray
    
    for(int i = 0; i < n; i++){
        sum = sum + arr[i];
        
        // If this is the maximum so far, update ans and the end index
        if(sum > ans) {
            ans = sum;
            start = tempStart; // Start of the new max subarray
            end = i;           // End of the new max subarray
        }
        
        // If the sum becomes negative, reset it and update tempStart
        if(sum < 0) {
            sum = 0;
            tempStart = i + 1; // Potential start of the next subarray
        }
    }
    
    // Printing the subarray that gives the max sum
    cout << "The max sum subarray is: ";
    for(int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return ans;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    cout << "Max subarray sum is : " << getMaxSubarraySum(arr, 9) << endl;
    
    return 0;
}
