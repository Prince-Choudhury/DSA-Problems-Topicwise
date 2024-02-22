#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this->arr = new int[size];
        this->size = size;
        this->front = -1;
        this->rear = -1;
    }

    void push(int val){
        //Queue Full
        if(rear == size - 1){
            cout<<"Queue is Overflow"<<endl;
            return;
        }

        else if(front == -1 & rear == -1){
            //Queue is empty
            front++;
            rear++;
            arr[rear] = val;
        }

        else{
            //Normal case
            rear++;
            arr[rear] = val;

        }
    }

    void pop(){
        if(front == -1 & rear == -1){
            cout<<"Underflow"<<endl;
            return;
        }

        else if(front == rear){
            //Single Element
            arr[front] = -1;
            front = -1;
            rear = -1;
        }

        else{
            //Normal case
            arr[front] = -1;
            front++;
        }
    }

    int getSize(){
        if(front == -1 & rear == -1){
            return 0;
        }
        else{
            return rear - front + 1;
        }
    }

    int getFront(){
        if(front == -1){
            cout<<"No front element"<<endl;
        }
        else{
            return arr[front];
        }
    }

    void print(){
        for(int i = 0; i<size; i++){
            cout<<arr[i]<<endl;
        }
        cout<<endl;
    }


};

int main(){

    Queue q(5);
    q.print();

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    q.pop();

   
    q.push(60);
    q.print();

    return 0;
}