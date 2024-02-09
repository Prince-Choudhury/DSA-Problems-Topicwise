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
};



int main(){

    return 0;
}