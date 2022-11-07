#include<iostream>
#include<limits.h>
using namespace std;

int getMinFromArray(int arr[], int n){
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, arr[i]);
    }
    return ans;
}
int main()
{   

    int arr[30];
    cout<<"Enter size"<<endl;
    int n;
    cin>>n;
    cout<<"Enter elements"<<endl;

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Minimum value is "<<getMinFromArray(arr, n);



    return 0;
}
