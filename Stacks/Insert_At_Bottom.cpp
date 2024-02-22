#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int &Ele){
    //Base case
    if(st.empty()){
        st.push(Ele);
        return;
    }

    //Ek case solve karunga
    int temp = st.top();
    st.pop();
    //Recursion
    insertAtBottom(st, Ele);
    //Backtrack
    st.push(temp);

}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);

    int Ele = 400;
    insertAtBottom(st, Ele);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}