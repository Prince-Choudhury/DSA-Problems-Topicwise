//Minimize the Heights II (GFG)

/*Given the heights of N towers and a value of K, Either increase or decrease the height of every tower by K (only once) where K > 0. After modifications, the task is to minimize the difference between the heights of the longest and the shortest tower and output its difference*/

#include<iostream>
#include<algorithm>
using namespace std;

int minimizeHeights(int arr[], int k, int n){

    sort(arr, arr+n);

    int mini = arr[0];
    int maxi = arr[n-1];

    int ans = maxi-mini;

    for (int i = 1; i < n; i++)
    {
        // If on subtracting k we got
        // negative then continue
        if (arr[i] - k < 0)
            continue;

        mini = min(arr[0]+k, arr[i]-k);

        maxi = max(arr[n-1]-k, arr[i-1]+k);

        ans = min(maxi-mini, ans);
    }
    
    return ans;
}
int main()
{
    int arr[] = { 7, 4, 2, 8, 3, 9 };
    int k = 6;
    int n = 6;

    int ans = minimizeHeights(arr, k, n);
    cout<<ans;
    
    return 0;
}