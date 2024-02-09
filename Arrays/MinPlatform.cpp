//Minimum Number of Platforms Required for a Railway/Bus Station

// Given the arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits. We are given two arrays that represent the arrival and departure times of trains that stop.

// Examples: 

// Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}, dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00} 
// Output: 3 

#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int MinPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr+n);
    sort(dep, dep+n);

    int platform = 1;
    int ans = INT_MIN;

    int i = 1;
    int j = 0;
    while (i<n && j<n)
    {
        if(arr[i]<=dep[j])
        {
            platform++;
            i++;
        }

        else 
        {
            platform--;
            j++;
        }

        ans = max(ans, platform);
    }
    
    return ans;
}

int main()
{
  
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000} ;
    
    int ans = MinPlatform(arr, dep, 6);
    cout<<ans;


    return 0;
}