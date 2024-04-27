#include <iostream>
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
    int n = 5;
    /*for(int row = 1; row<=n;row++){
       if(row == 1 || row == 2 || row == n){
        for (int col = 1; col<=row; col++)
        {
            cout<<col;
        }
        
       }
       else{
        cout<<1;
        for(int col = 1; col<=row-2;col++){
            cout<<" ";
        }
        cout<<row;
       }
       cout<<endl;
    }*/

//Another approach
    for(int row=1; row<=n;row++){
        for(int col = 1; col<=row; col++){
            if(col==1 || col == row || row == n){
                cout<<col;
            }
            else
                cout<<" ";
        }
        cout<<endl;
    }


    return 0;
}