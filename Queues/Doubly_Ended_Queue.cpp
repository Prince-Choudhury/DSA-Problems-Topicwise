#include<iostream>
#include<deque>
using namespace std;

int main(){

    deque<int>dq;

    dq.push_front(10);
    dq.push_front(20);
    dq.push_front(30);
    dq.push_front(40);

    dq.pop_front();
    dq.pop_front();

    dq.push_back(100);
    dq.push_back(200);
    dq.push_back(300);
    dq.push_back(400);

    dq.pop_back();
    dq.pop_back();

    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    cout<<dq.size()<<endl;
    return 0;
}

