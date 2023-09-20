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

int findComplement(int num){
    int mask = 0;
    while (mask<num)
    {
        mask = (mask<<1) | 1; 
    }
    int ans = (~num) & mask;
    return ans;
    
}
int main() {
    int n;
    cout<<"Enter the number that you want complement : ";
    cin>>n;
    cout<<findComplement(n);

    return 0;
}