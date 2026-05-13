#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n) {
    int r = row, c = col;
    
    // Check left side row
    while(c >= 0) {
        if(board[r][c] == 'Q') return false;
        c--;
    }
    
    // Upper diagonal
    r = row; c = col;
    while(r >= 0 && c >= 0) {
        if(board[r][c] == 'Q') return false;
        r--; c--;
    }
    
    // Lower diagonal
    r = row; c = col;
    while(r < n && c >= 0) {
        if(board[r][c] == 'Q') return false;
        r++; c--;
    }
    
    return true;
}

void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
    if(col == n) {
        ans.push_back(board);
        return;
    }
    
    for(int row = 0; row < n; row++) {
        if(isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.'; // backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    
    for(int i = 0; i < n; i++)
        board[i] = s;
        
    solve(0, board, ans, n);
    return ans;
}

int main() {
    int n;
    cout << "Enter value of N: ";
    cin >> n;

    vector<vector<string>> result = solveNQueens(n);

    cout << "\nTotal solutions: " << result.size() << endl;

    for (int i = 0; i < result.size(); i++) {
        cout << "\nSolution " << i + 1 << ":\n";
        for (string row : result[i]) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}