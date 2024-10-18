#include <iostream>
#include<set>
#include<string.h>
using namespace std;

int main(){
    string s = "aaabbccd";
    int k = 2;
    int n = s.length();
    int maxlen = 0;

    for(int i = 0; i<n; i++){
        set<int>st;
        for(int j = 0; j<n; j++){
            st.insert(s[j]);
            if(st.size()<=k){
                maxlen = max(maxlen, j-i+1);
            }
        }
    }

    cout<<"Longest Substring is : "<<maxlen<<endl;

    return 0;
}