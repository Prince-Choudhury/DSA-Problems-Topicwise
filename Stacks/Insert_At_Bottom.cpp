#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int &Ele){
    if(st.empty()){
        st.push(Ele);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, Ele);
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