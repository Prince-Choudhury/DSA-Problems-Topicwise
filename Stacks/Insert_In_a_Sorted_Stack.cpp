#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int> &st, int & Element){
    //Base Case
    if(st.empty() || Element > st.top()){
        st.push(Element);
        return;
    }

    //Ek case solve Karunga
    int temp = st.top();
    st.pop();
    //Recursion
    insertSorted(st, Element);
    //Backtrack
    st.push(temp);
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    int Element = 25;
    insertSorted(st, Element);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}