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

void sortStack(stack<int> &st){
    //base case
    if(st.empty()){
        return;
    }

    //ek case solve karunga
    int temp = st.top();
    st.pop();
    //Recursion
    sortStack(st);
    //Backtrack
    insertSorted(st, temp);
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(5);
    st.push(12);
    st.push(8);
    st.push(9);

    sortStack(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}