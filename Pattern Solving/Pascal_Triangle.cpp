#include<iostream>
using namespace std;


int fact(int n){
    int ans = 1;
    for (int i = n; i >=1 ; i--)
    {
        ans = ans*i;
    }
    return ans;
}


int nCr(int n, int r){

    int val1 = fact(n);
    int val2 = fact(n-r);
    int val3 = fact(r);

    int ans = (val1)/(val2 * val3);

    return ans;

}

int main()
{


    int n = 5;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            int value = nCr(row, col);
            cout<< value;
        }
        cout<<endl;

    }
    
    return 0;
}
