#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char c){
    for(int i=0; i<9; i++){
        if(board[i][col]==c || board[row][i]==c)
            return false;

        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
            return false;
    }
    return true;
}

bool SudokoSolver(vector<vector<char>> &board){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j]=='.'){
                for(char c='1'; c<='9'; c++){
                    if(isValid(board, i, j, c)){
                        board[i][j]=c;
                        if(SudokoSolver(board))
                            return true;
                        board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0)
            cout << "------+-------+------\n";  // horizontal separator every 3 rows

        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0)
                cout << "| ";  // vertical separator every 3 columns

            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    vector<vector<char>> board(9, vector<char> (9, '.'));
    board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    if(SudokoSolver(board)){
        printBoard(board);
    }else{
        cout<<"No solution exist";
    }
}