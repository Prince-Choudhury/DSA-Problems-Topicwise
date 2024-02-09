#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

string reverseString(string temp){
    int s = 0;
    int e = temp.length() -1;

    while (s<e)
    {
        swap(temp[s], temp[e]);
        s++;
        e--;
    }
    return temp;
}

string reverseWords(string str){
    string temp = "";

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == ' ' || str[i] == '\0')
        {
            return reverseString(temp);
            temp = "";
        }
        
        else
             temp.push_back(str[i]);

    }
}


int main()
{
    string str = "My name is Prince";
    cout<<reverseWords(str);
    return 0;
}