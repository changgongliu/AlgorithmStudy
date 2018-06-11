#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "assert.h"
using namespace std;
class Solution1 {
private:
    vector<vector<int> > ans;
    void generateCombine(const int& n, int k, vector<int>& p, int index) {
        if(k == 0 & index <= n+1) {
            ans.push_back(p);
            return;
        }
        for(int i = index; i <= n; ++i) {
            p.push_back(i);
            generateCombine(n, k-1, p, i+1);

            p.pop_back();
        }
        return;
    }
public:
    vector<vector<int> > combine(int n, int k) {
        ans.clear();
        if( n == 0 || k ==0 || k > n)
            return ans;
        vector<int> p;
        generateCombine(n, k, p, 1);
        return ans; 

    }
};
class Solution2 {
public:
vector<string> work(int k) {
    vector<string> res;
    if(k > 10) return res;
    for (int i = 0; i < (1 << 10); i++) {
        if(__builtin_popcount(i) == k) {
            int h = i >> 6;
            if(h > 11) continue;
            int m = i & ((1 << 6) - 1);
            if(m > 59) continue;
            stringstream ss;
            ss << h;
            ss << ":";
            if(m < 10) ss << "0";
            ss << m;
            string x = ss.str();
            res.push_back(x);
        }
    }
    return res;
}
   vector<string> readBinaryWatch(int num) {
        return work(num);
    }
};
class Solution3 {
    int m = 0, n = 0;
    int suqare[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;
    bool isInArea(int x, int y) {
        return x>=0 && x < m && y >= 0 && y < n;
    }
    void searchIsland(vector<vector<char>>& grid, int startX, int startY) {
        visited[startX][startY] = true;

        for(int i = 0; i < 4; i ++) {
            int newX = startX + suqare[i][0];
            int newY = startY + suqare[i][1];
            if(isInArea(newX, newY) && !visited[newX][newY] && grid[newX][newY] == '1') {
                searchIsland(grid, newX, newY);
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {

        int res = 0;
        if(grid.size() == 0)
            return res;
        
        m = grid.size();
        assert(m>0);
        n = grid[0].size();

        visited = vector<vector<bool>>(m ,vector<bool>(n, false));
        for( int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                if(isInArea(i, j) && grid[i][j] == '1' && !visited[i][j]) {
                    searchIsland(grid, i, j);
                    res ++;
                }
            }
        }
        return res;
    }
};
class Solution4 {
    int m = 0, n = 0;
    int suqare[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited;
    bool isInArea(int x, int y) {
        return x>=1 && x < m-1 && y >= 1 && y < n-1;
    }
    void searchAndSolve(vector<vector<char>>& board, int startX, int startY) {
        board[startX][startY] = 'X';
        visited[startX][startY] = true;
        for(int i = 0; i < 4; i ++) {
            int newX = startX + suqare[i][0];
            int newY = startY + suqare[i][1];
            if(isInArea(newX, newY) && board[newX][newY] == 'O' && !visited[newX][newY]) {
                if(board[startX][startY] == 'O'){
                    visited[newX][newY] = true;
                    return;
                }               
                searchAndSolve(board, newX, newY);
                if(board[newX][newY] == 'O'){
                    board[startX][startY] = 'O';
                    return;
                }
                   
            }
            else if(!isInArea(newX, newY) && board[newX][newY] == 'O') {
                board[startX][startY] = 'O';
                break;
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        
        m = board.size();
        assert(m>0);
        n = board[0].size();

        visited = vector<vector<bool>>(m ,vector<bool>(n, false));       
        for( int i = 1; i < m-1; i++) {
            for(int j = 1; j < n-1; j++){
                if(isInArea(i, j) && board[i][j] == 'O' && !visited[i][j]) {
                    searchAndSolve(board, i, j);
                }
            }
        }
        return;       
    }
};
class Solution5 {
private:
    vector<vector<string>> res;
    vector<bool> col, diag1, diag2;
    vector<string> generateString(int n, vector<int> Value) {
        vector<string> res(n, string(n, '.'));
        for(int i = 0; i < Value.size(); i ++)
            res[i][Value[i]] = 'Q';
        return res;
    }
    void putNQueens(int n, int index, vector<int>& tmp) {
        if(index == n) {
            res.push_back(generateString(n, tmp));
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!col[i] && !diag1[index+i] && !diag2[index-i+n-1]) {
                tmp.push_back(i);
                col[i] = true;
                diag1[index+i] = true;
                diag2[index-i+n-1] = true;
                putNQueens(n, index+1, tmp);

                col[i] = false;
                diag1[index+i] = false;
                diag2[index-i+n-1] = false;
                tmp.pop_back(); 
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        if(n <= 0)
            return res;
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2*n - 1, false);
        diag2 = vector<bool>(2*n - 1, false);
        vector<int> tmp;
        putNQueens(n, 0, tmp);
        return res;
    }
};
class Solution {
private:
    vector<vector<bool>> mapRow;//表示第i行
    vector<vector<bool>> mapCol;
    vector<vector<bool>> mapArea;
    bool doSolve(vector<vector<char>>& board, int count) {
        if(count>=81)
            return true;
        for(int i = count; i < 81; i++) {
            int row = i/9;
            int col = i%9;
            if(board[row][col] != '.')
                continue;
            for(int j = 0; j < 9; j++) {
                int arg1 = row/3*3+col/3;
                if(!mapRow[row][j] && !mapCol[col][j] && !mapArea[(row/3)*3 + col/3][j]) {
                    mapRow[row][j] = true;
                    mapCol[col][j] = true;
                    mapArea[(row/3)*3+col/3][j] = true;
                    board[row][col] = j+1+'0';
                    if(doSolve(board, i+1)) 
                        return true;
                    mapRow[row][j] = false;
                    mapCol[col][j] = false;
                    mapArea[row/3*3+col/3][j] = false;
                    board[row][col] = '.';
                }
            }
            return false;
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        assert(board.size() == 9);
        assert(board[0].size() == 9);
        mapRow = vector<vector<bool>>(9, vector<bool>(9, false));
        mapCol = vector<vector<bool>>(9, vector<bool>(9, false));
        mapArea = vector<vector<bool>>(9, vector<bool>(9, false));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j]-'1';//索引从0开始
                    mapRow[i][num] = true;
                    mapCol[j][num] = true;
                    mapArea[(i/3)*3+(j/3)][num] = true;
                }
           }
        }
        doSolve(board, 0);
        return;
    }
};
int main() {
    Solution tmp = Solution();
    vector<vector<char>> grid = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    cout<<int('0')<<endl;
    tmp.solveSudoku(grid);
    return 0;
}