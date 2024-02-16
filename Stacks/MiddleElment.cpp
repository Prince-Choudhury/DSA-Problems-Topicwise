#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st, int &pos, int &ans){
    //base case
    if(pos == 1){
        ans = st.top();
        return;
    }
    else{
        //ek case solve karunga
        pos--;
        int temp = st.top();
        st.pop();
        //Recursion
        solve(st, pos, ans);
        //Backtrack
        st.push(temp);
    }
}

int getMiddleElement(stack<int> &st){
    if(st.empty()){
        cout<<"Stack is empty" <<endl;
        return -1;
    }

    int size = st.size();
    int pos = -1;
    //odd
    if(size & 1){
        pos = size/2 + 1;
    }
    else{
        pos = size/2;
    }

    int ans = -1;
    solve(st, pos, ans);
    return ans;
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    cout<<"Before size : "<<st.size()<<endl;
    int mid = getMiddleElement(st);
    cout<<"Middle element is : "<<mid<<endl;
    cout<<"After size : "<<st.size()<<endl;

    return 0;
}