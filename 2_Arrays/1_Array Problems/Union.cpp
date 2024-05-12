// Find union of two sorted arrays
// There should be no duplicate element present in the sorted arrays

#include <iostream>
using namespace std;

void printUnion(int arr1[], int arr2[], int n, int m)
{

    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] > arr2[j])
            cout << arr2[j++] << " "; // cout<<arr2[j++] is equivalent to cout<<arr2[j],  j++

        else if (arr1[i] < arr2[j]) // cout<<arr1[i],  i++
            cout << arr1[i++] << " ";
        else
            cout << arr2[j++] << " "; // cout<<arr2[j],  j++
        i++;
    }

    // Print remaining elements of the larger array

    while (i < n)
    {
        cout << arr1[i++] << " ";
    }

    while (j < m)
    {
        cout << arr2[j++] << " ";
    }
}

int main()
{
    int arr1[] = {2, 3, 5, 7};
    int arr2[] = {3, 4, 5, 6, 7};

    printUnion(arr1, arr2, 4, 5);

    return 0;
}



// Using set
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m){
        
        set<int>st;
        for(int i = 0; i<n; i++){
            st.insert(arr1[i]);
        }
        
        for(int i = 0; i<m; i++){
            st.insert(arr2[i]);
        }
        
        vector<int>ans;
        for(auto i:st){
            ans.push_back(i);
        }
        
        return ans;
    }
    
};


//Using map

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m){
        
        map<int, bool>mp;
        for(int i = 0; i<n; i++){
            mp[arr1[i]] = 1;
        }
        
        for(int i = 0; i<m; i++){
            mp[arr2[i]] = 1;
        }
        
        vector<int>ans;
        for(auto i:mp){
            ans.push_back(i.first);
        }
        
        return ans;
    }
    
};

