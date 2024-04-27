// Sort an array of 0's, 1's and 2's
// arr[] = {1, 0, 2, 2, 0, 1, 1} Without sort function
// o/p : {0, 0, 1, 1, 1, 2, 2}

#include <iostream>
#include <algorithm>
using namespace std;

void SortZeroOneTwo(int arr[], int n){
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            countZero++;
        else if(arr[i] == 1)
            countOne++;   
        else
            countTwo++;       
    }
    
    int i = 0;
    while (countZero--)  // while(zeroOne != 0),   zero--
    {
        arr[i] = 0;
        i++;
    
    }
    
    while (countOne--)  
    {
        arr[i] = 1;
        i++;
    
    }

    while (countTwo--)  
    {
        arr[i] = 2;
        i++;
    
    }

}


int main()
{   
    int arr[] = {1, 0, 2, 2, 0, 1, 1};
    int size = 7;
    //sort(arr, arr + size); Using sort fun we will get the ans directly
    // But we have to do without sort fun

    SortZeroOneTwo(arr, 7);

    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
