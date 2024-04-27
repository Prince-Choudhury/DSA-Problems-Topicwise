#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool checkAnagram(string str1, string str2){

    int freq[26] = {0};

    //inc count for string str1
    for (int i = 0; i < str1.length(); i++)
    {
        char ch = str1[i];
        int index = ch - 'a';

        freq[index] ++;
    }

    //dec count for str2
    for (int i = 0; i < str2.length(); i++)
    {
        char ch = str2[i];
        int index = ch - 'a';

        freq[index] --;
    }
    
    
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {   
            return false;
        }
        
    }
    return true;
}


int main()
{

    string str1 = "Prince";
    string str2 = "ecrinP";

    cout<<checkAnagram(str1, str2);

    return 0;
}


