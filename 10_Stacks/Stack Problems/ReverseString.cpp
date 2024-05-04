#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<char>st;
    string str = "Prince";
    for(int i = 0; i<str.length(); i++){
        st.push(str[i]);
    }
    cout<<endl;

    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
    return 0;
}