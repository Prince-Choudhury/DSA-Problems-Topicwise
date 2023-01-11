#include<iostream>
#include<algorithm>
#include<vector>
#include <string.h>
using namespace std;

bool checkPalindrom(char str[], int n){

    int s = 0;
    int e = n - 1;
    while (s<=e)
    {
        if (str[s] != str[e])
        {
            return false;
        }
        
        else{
            s++;
            e--;
        }
           
    }
    return true;
}

int main()
{

    char a[10] = "NooN";
    int len = strlen(a);

    cout<<"Palindrom or Not : "<<checkPalindrom(a, len);

    return 0;
}






