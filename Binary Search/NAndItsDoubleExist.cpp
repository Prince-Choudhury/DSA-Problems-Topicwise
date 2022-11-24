#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool binarySearch(vector<int> &arr, int s, int e, int target){

    while (s<=e)
    {
        int mid = s + (e - s)/2;

        if (target == arr[mid])
        {
            return true;
        }
        
        if (arr[mid] > target)
        {
            e = mid - 1;
        }
        
        else 
            s = mid + 1;
    }
    return false;

}


bool checkIfExist(vector<int> &arr){

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {   
        //positive no
        if (arr[i] >= 0 && binarySearch(arr, i+1 , arr.size()-1, 2*arr[i]))
        {   
            return true;
        }
        //negative no  
        if (arr[i] < 0 && arr[i] % 2 == 0 && binarySearch(arr, i+1, arr.size()-1, arr[i]/2 ))
        {
            return true;
        }
        
    }
    return false;   
}

int main()
{
    vector<int> arr{-4, -5, -2, 10, 5, 7, 18};

    cout<<checkIfExist(arr);

    return 0;
}