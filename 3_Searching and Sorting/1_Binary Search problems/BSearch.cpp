#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearch(int arr[], int n, int target)
{
    int start = 0;
    int end = n-1;
    
    int mid = start + (end - start)/2;   // mid = (start+end)/2

    while (start<=end)
    {
        int midElement = arr[mid];

        if(midElement == target)
            return true;

        if(target<midElement)   
            end = mid - 1;
        else
            start = mid + 1;    

        mid = start + (end - start)/2;     // mid = (start+end)/2

    }

    return false;        // Element not found till line no. 27
                        // therefore return false that is no. not found 
}

int main()
{

    int arr[] = {3,5,7,9,11,15,18}; 
    int target = 15;
    int n = 7;

    // binary_seardch() is an inbuilt fun. 
    //we can use it without writing whole code
    /*if(binary_search(arr, arr+n, target)){       
        cout<<"Element found";
    }
    else{
        cout<<"Element not found";
    }

    cout<<endl;*/

    if(binarySearch(arr, n, target)){       
        cout<<"Element found";
    }
    else{
        cout<<"Element not found";
    }

    return 0;
}


