#include<iostream>
#include<vector>
using namespace std;

void wavePrintMatrix(vector<vector<int> > mat){
    int m = mat.size();
    int n = mat[0].size();
    for(int startCol = 0; startCol<n; startCol++){
        //Even no of col -> TOP TO BOTTOM
        if((startCol & 1) == 0){
            for(int i = 0; i<m; i++){
                cout<<mat[i][startCol]<<" ";
            }
            
        }
        
        else{
            //Odd no of col -> BUTTOM TO TOP
            for(int i = m-1; i>=0; i--){
                cout<<mat[i][startCol]<<" ";
            }
        }
    }
}

int main(){

    vector<vector<int> > mat
    {
        {1,2,3,4}, 
        {5,6,7,8},
        {9,10,11,12}
    };
    wavePrintMatrix(mat);
    return 0;
}