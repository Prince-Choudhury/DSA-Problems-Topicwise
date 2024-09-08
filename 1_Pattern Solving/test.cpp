#include <iostream>
using namespace std;

/*
int main() {
    int n = 5;

    for(int i = 1;i<=n;i++){
        for(int j= 1; j<=n-i; j++){
            cout<<" ";
        }

        for(int j = 1; j<=2*i-1; j++){
            cout<<j;
        } 
        cout<<endl;
    }
    return 0;  
}*/

int main(){

    int n = 5;
    int start = 0;

    for(int i = 1; i<=n; i++){

        for(int j = 1; j<=i; j++){
            cout<<start+j;
            start = start-1;
        }
        cout<<endl;
        
    }

    return 0;
}