//Find maximum number in an Array

#include <iostream>
#include <limits.h>
using namespace std;

void getmaxarray(int arr[], int n){
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        ans = max(INT_MIN, arr[i]);
    }
    cout<< " The max no is " << ans;

}

int main()
{
    int arr[]={3, 24, 53, 2, 22, 98};

    getmaxarray(arr, 6);
    

    return 0;
}


// GCD of array using vector


/*
int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int maxi = -99999, mini = 999999;
        for (auto i: nums)
        {
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        
        while (mini != maxi)
        {
            if (maxi > mini)
                maxi -= mini;
            else
                mini -= maxi;
        }
        return mini;     
        
    }
*/    