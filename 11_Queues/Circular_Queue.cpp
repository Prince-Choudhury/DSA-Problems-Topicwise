#include<iostream>
using namespace std;

class Cqueue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Cqueue(int size){
        this->arr = new int[size];
        this->size = size;
        this->front = -1;
        this->rear = -1;
    }

    void push(int val){
        //1. Overflow
        if(front == 0 && rear == size -1 || (rear == front - 1)){
            cout<<"Overflow"<<endl;
            return;
        }

        //2. Empty Case -> Single ELement
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
        }

        //3. Circular Queue
        else if(rear == size - 1 && front != 0){
            rear = 0;
            arr[rear] = val;
        }
        //4. Normal Case
        else{
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){
        //1. Underflow
        if(front == -1 && rear == -1){
            cout<<"Underflow"<<endl;
            return;
        }

        //2. Single element
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        //3. Circular nature

        else if(front == size - 1){
            arr[front] = -1;
            front = 0;
        }

        //4. Normal flow
        else{
            arr[front] = -1;
            front++;
        }
    }

    void print(){
        cout<<"front = "<<front<<", "<<"rear = "<<rear<<endl;
        cout<<"Printing Queue : ";
        for(int i = 0; i<size; i++){
            cout<<" "<<arr[i];
        }
        cout<<endl;
    }
};


int main(){
    Cqueue q(5);

    q.push(10);
    q.print();
    q.push(20);
    q.print();
    q.push(30);
    q.print();
    q.push(40);
    q.print();
    q.push(50);
    q.print();

    q.push(60);

    q.pop();
    q.pop();
    q.pop();
    q.print();

    q.push(100);
    q.print();

    q.push(200);
    q.print();

    q.push(300);
    q.print();

    //Not showing Overflow condition
    //It is replacing the val 
    //It should return overflow but it is overiding the val
    //so add one more condition (rear == front - 1;)
    q.push(400);
    
    return 0;
}