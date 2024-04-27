#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void func1(int ** q){
    q = q + 1;
}

void func2(int ** q){
    * q = * q + 1;
}

void func3(int ** q){
    ** q = ** q + 1;
}

int main(){

    int a = 5;
    int * p = &a;
    int ** q = &p;

    cout<<"Before : "<<q<<endl;
    cout<<"Before : "<<* q<<endl;
    cout<<"Before : "<<** q<<endl;

    func3(q);

    cout<<"After : "<<q<<endl;
    cout<<"After : "<<* q<<endl;
    cout<<"After : "<<** q<<endl;


    char ch = 'a';
    char *ptr = &ch;
    ch++;
    cout<<*ptr;


    int a[] = {1,2,3,4};
    int *p = a++;
    cout<<*p<<endl;
    return 0;
}    
