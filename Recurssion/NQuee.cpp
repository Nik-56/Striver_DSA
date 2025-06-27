#include <bits/stdc++.h>
using namespace std;

void Nqueen(int col, vector<vector<char>> &res, int n, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal){
    if(col==n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"----------------------------------------------"<<endl;
        return;
    }

    for(int row=0; row<n; row++){
        if(leftRow[row]==0 && upperDiagonal[n-1+col-row]==0 && lowerDiagonal[row+col]==0){
            leftRow[row]=1;
            upperDiagonal[n-1+col-row]=1;
            lowerDiagonal[row+col]=1;
            res[row][col]='Q';
            Nqueen(col+1, res, n, leftRow, upperDiagonal, lowerDiagonal);
            leftRow[row]=0;
            upperDiagonal[n-1+col-row]=0;
            lowerDiagonal[row+col]=0;
            res[row][col]='-';
        }
    }

}

int main(){
    int n;
    cout<<"Enter N: ";
    cin>>n;
    vector<vector<char>> res(n, vector<char> (n, '-'));
    vector<int> leftRow(n, 0), upperDiagonal(2*n-1), lowerDiagonal(2*n-1);
    Nqueen(0, res, n, leftRow, upperDiagonal, lowerDiagonal);
}