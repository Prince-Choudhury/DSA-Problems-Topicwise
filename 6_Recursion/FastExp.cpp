#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int expo(int n){

    if(n==0)
        return 1;

    int SmallerProblemAns = expo(n/2);

    if(n & 1)  // if n is odd
        return SmallerProblemAns * SmallerProblemAns * 2;

    else
        return SmallerProblemAns * SmallerProblemAns;        
}

int main(){
    
    cout<<"Ans is : "<<expo(10);

    return 0;
}