// Recursive Approach

#include <iostream>
#include<stack>
using namespace std;

/*

void solve(stack<int> &st, int& pos, int &ans) {
  //base case
  if(pos == 1) {
    //ans =  st.top();
    cout << "Deleting "<< st.top() << endl;
    st.pop();
    return;
  }
  //1 case hum solve krenge
  pos--;
  int temp = st.top();
  st.pop();
  //recursion
  solve(st,pos,ans);
  //backtracjk
  st.push(temp);
}

int getMiddleElement(stack<int> &st) {
  int size = st.size();
  if(st.empty()){
    cout << "Stack is empty, no middle element" << endl;
    return -1;
  }
  else {
    //stack is not empty
    //odd
    int pos = 0;
    if(size & 1) {
      pos = size/2 + 1;
    }
    else {
      //even
      pos = size/2;
    }
    int ans = -1;
    solve(st,pos,ans);
    return ans;
  }
}

int main() {
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(50);
  st.push(60);

  cout << "before size : " << st.size() << endl; 
  int mid = getMiddleElement(st);
  cout << "Middle element: " << mid << endl;

  cout << "after size : " << st.size() << endl; 
  return 0;
}

*/
// Iterative Approach

#include <iostream>
#include <stack>
using namespace std;

int findMiddle(stack<int>& s) {
    int n = s.size();
    int midIdx = n / 2;
    
    stack<int> tempStack;
    // Pop elements until we reach the middle
    for (int i = 0; i < midIdx; i++) {
        tempStack.push(s.top());
        s.pop();
    }
    
    // The middle element
    int middle = s.top();
    s.pop();
    
    // Push the elements back into the original stack
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
    
    return middle;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    
    
    cout << "Middle element: " << findMiddle(s) << endl; 
    cout<< "Size after deletion : "<<s.size()<<endl; 
    
    return 0;
}
