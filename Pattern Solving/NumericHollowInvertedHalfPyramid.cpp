#include <iostream>
#include<limits.h>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    /*int n= 5;
    for(int row=1;row<=n;row++){
        if(row == 1){
            for(int col = 1; col<=n;col++){
                cout<<col;
            }
        }
        else if (row == n)
            cout<<n;

        else{
            cout<<row;
            for(int col = 1; col<=n-row-1; col++){
                cout<<" ";
            }
            cout<<n;
        }
        cout<<endl;
        
    }*/

// Another Approach
    int n = 5;
    for(int row = 1; row<=n;row++){
        for(int col = row; col<=n; col++){
            if(row ==1 || row==col || col==n){
                cout<<col;
            }
            else
                cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}