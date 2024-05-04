#include<iostream>
using namespace std;

class Stack{
    public:
        int* arr;
        int size;
        int top;

        Stack(int data){
            this->arr = new int[size];
            this->size = size;
            this->top = -1;
        }

        void push(int data){
            if(top == size-1){
                cout<<"Can't insert, Overflow"<<endl;
                return;
            }   

            else{
                top++;
                arr[top] = data;
            }
        }

        void pop(){
            if(top == -1){
                cout<<"Underflow"<<endl;
                return;
            }
            else{
                top--;
            }
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }

        int getTop(){
            if(top == -1){
                return -1;
            }
            else{
                return arr[top];
            }
        }

        int getSize(){
            return top+1;
        }

};



int main(){

    return 0;
}