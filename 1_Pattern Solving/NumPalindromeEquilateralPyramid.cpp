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
    // row = i, col = j
    int n = 5;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cout<<j;
        }
        
        for (int k = 1; k < i; k++)
        {
            cout<<k;
            
        }
        cout<<endl;
    }

   
    
    

    return 0;
}