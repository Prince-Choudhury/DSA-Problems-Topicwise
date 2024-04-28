#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() 
{
    string str = "Prince";
    int s = 0;
    int e = str.length() -1;

    while (s<e)
    {
        swap(str[s], str[e]);
        s++;
        e--;
    }
    
    cout<<str;
    
    return 0;
}