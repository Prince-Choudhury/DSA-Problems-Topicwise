#include<iostream>
using namespace std;

bool LinearSearch(int arr[], int size, int target){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==target)
            return true;
    }
    
    return false;    
   
}

int main(){

    int arr[100];
    int n;
    cout<<"Enter size of the Array"<<endl;
    cin>>n;
    
    cout<<"Enter Arrary Elements"<<endl;

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    if(LinearSearch(arr, 5, 4))
        cout<<"Element found"<<endl;
    else
        cout<<"Element Not found "<<endl;

    // OR cout<<"Searching 4 -> "<<LinearSearch(arr, 5, 4);
    

    return 0;
}
