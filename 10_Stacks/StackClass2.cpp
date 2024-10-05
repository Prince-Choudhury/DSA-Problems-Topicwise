// 1. implement 2stack using 1 array

#include <iostream>
#include<stack>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;
    Stack(int size)
    {
        this->size = size;
        this->arr = new int[size];

        this->top1 = -1;
        this->top2 = size;
    }

    void push1(int data)
    {
        if (abs(top2 - top1) == 1)
        {
            cout << "Stack OverFlow!" << endl;
            return;
        }
        top1++;
        arr[top1] = data;
    }

    void push2(int data)
    {
        if (abs(top2 - top1) == 1)
        {
            cout << "Stack OverFlow!" << endl;
            return;
        }
        top2--;
        arr[top2] = data;
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack underFlow!" << endl;
            return;
        }
        arr[top1] = 0;  // No need to set arr[top1] = 0, It will automatically overwrite the value
        top1--;
    }

    void pop2()
    {
        if (top2 == size)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }
        arr[top2] = 0;
        top2++;
    }

    int getTop1()
    {
        return arr[top1];
    }

    int getTop2()
    {
        return arr[top2];
    }
};



// 2. Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i = 0; i<s.length(); i++){
            char ch = s[i];

            if(ch == '(' || ch == '[' || ch == '{'){
                //for open bracket -> just push
                st.push(ch);
            }

            else{
                // Closing bracket
                if(!st.empty()){
                    if(ch == ')' && st.top() == '('){
                        st.pop();
                    }
                    else if(ch == ']' && st.top() == '['){
                        st.pop();
                    }
                    else if(ch == '}' && st.top() == '{'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }

        if(st.size() == 0){
            return true;
        }
        else{
            return false;
        }
        
    }
};

/*Key Concept to Remember:

The code checks each closing parenthesis ) and ensures that it contains at least 
one operator between the opening ( and the closing ). If no operators are found inside 
the parentheses, they are considered redundant.*/

// 3. check for redundant bracket
bool checkRedundantBracket(string s)
{
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            st.push(ch);
        else if (ch == ')')
        {
            int operatorCount = 0;
            while (st.size() != 0 && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                    operatorCount++;
                st.pop();
            }
            st.pop();
            if (operatorCount == 0)
                return 1;
        }
    }
    return 0;
}
int main()
{
    // Stack st(5);
    // st.push1(1);
    // st.push1(2);
    // st.push1(3);
    // st.push2(4);
    // cout << st.getTop1() << endl;
    string str = "((a+b)*(a+b))";
    cout << checkRedundantBracket(str) << endl;
    return 0;
}