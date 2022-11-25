#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool checkPalindrom(string str1){

    string str2 = "malayalam";;
    int s = 0;
    int e = str1.length() -1;

    while (s<e)
    {
        swap(str1[s], str1[e]);
        s++;
        e--;
    }
    
    if (str1 == str2)
    {
        return true;
    }
    else    
        return false;

}

int main()
{

    string str = "malayalam";

    cout<<checkPalindrom(str);

    return 0;
}