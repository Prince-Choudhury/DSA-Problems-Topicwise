#include<iostream>
using namespace std;

int main(){

    int n = 5;
    int start = 1;
    for(int i = 1; i<=n; i++){
        if(i&1){  // i odd
            start = 1;
        }
        else{  // i even
            start = 0;
        }

        for(int j= 1; j<=i; j++){
            cout<<start;
            start = 1-start;
        }
        cout<<endl;

    }
    return 0;
}