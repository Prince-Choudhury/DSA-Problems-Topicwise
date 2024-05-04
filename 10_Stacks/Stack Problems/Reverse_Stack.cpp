#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int &Element){
    //Base case
    if(st.empty()){
        st.push(Element);
        return;
    }

    //Ek case solve karunga
    int temp = st.top();
    st.pop();
    //Recursion
    insertAtBottom(st, Element);
    //Backtrack
    st.push(temp);

}

void reverseStack(stack<int> &st){
    //Base case
    if(st.empty()){
        return;
    }
    //Ek case solve karunga
    int temp = st.top();
    st.pop();
    //Recursion
    reverseStack(st);
    //Backtrack
    insertAtBottom(st, temp);
}



int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}