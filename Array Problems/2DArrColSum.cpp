// Print Column wise Sum and maximum column sum

#include <iostream>
#include <limits.h>
using namespace std;


int ColSum(int arr[3][4], int row, int col){
    int maxi = INT_MIN;

    for (int i = 0; i < col; i++)
    {
        int sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum = sum + arr[j][i];
        }
        maxi = max(maxi, sum);
        cout<<sum<<" ";

    }
    cout<<endl;
    return maxi;
}

int main()
{
    int arr[3][4] = {3,5,11,2,7,9,8,0,5,0,1,3};

    cout<<"Maximum col Sum is "<<ColSum(arr, 3, 4);

    return 0;
}