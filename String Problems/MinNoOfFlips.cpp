#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


char flip(int expected){

    if (expected == '0')
    {
        return '1';
    }
    else
        return '0';
}


int getFlips(string str, char expected){

    int cntflips = 0;

    for (int i = 0; i < str.length(); i++)
    {    
        if (str[i] != expected)
        {
            cntflips ++;
        }

        expected = flip(expected);
        
    }
    return cntflips;
}


int main()
{
    string str = "0010";

    int ans0 = getFlips(str, '0');
    cout<<ans0<<endl;

    int ans1 = getFlips(str, '1');
    cout<<ans1<<endl;

    int ans = min(ans0, ans1);

    cout<<"Min no of flips : "<<ans;


    return 0;
}