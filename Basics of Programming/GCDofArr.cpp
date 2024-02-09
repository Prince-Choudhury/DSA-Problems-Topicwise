#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;


int findGCD(int arr[], int n) {
    sort(arr, arr + n);

         int a, b;
         a = arr[0]; // Smallest element of the array
         b = arr[n-1];  // Largest element of the array

         if(a == 0)
            return b;
         else
            return a;

         while(a!=b){
             if(a>b)
                a = a-b;
             else
                b = b-a;   
              
         }
         return a;   // GCD of smallest and largest element    
        
    }


int main(){
    int arr[20];
    int n;
    cout<<"Enter the size of an array";
    cin>>n; 
    cout<<"Enter array elements";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int ans = findGCD(arr, 5);
    cout<<""<<ans;
    return 0;
}