#include<iostream>
#include<queue>
using namespace std;



// Intution: Traversals containing boundary 0's can't be covered in all 4-directions by X's
// ALGORITHM: Start traversal from the border 0's and mark them that they'll not be converted, and convert the remaining



// ====================================================================== Approach (BFS) ======================================================================
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // Edge case
        if(board.empty()) return;

        vector<vector<int>> visited(board.size(), vector<int> (board[0].size(), 0));
        queue<pair<int, int>> q;    // row, col

        // Initial Configuration
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == 'O' && (i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1) && !visited[i][j]) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()) {
            // Put front node into answer
            int r = q.front().first, c = q.front().second;
            q.pop();

            // Push all non-visited nieghbours of front node into queue
            vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
            for(auto dir:directions) {
                int row = r + dir.first, col = c + dir.second;

                // Make sure to check bounds first in below condition, otherwise accessing visited or board will give out of bound access error
                if(row>=0 && row<board.size() && col>=0 && col<board[0].size() && !visited[row][col] && board[row][col] == 'O') {
                    q.push({row, col});
                    visited[row][col] = 1;
                }
            }
        }

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// TC : O(N*M)
// SC : O(N*M)


// ================================================================= Alternate approach (DFS) =================================================================
class Solution {
public:
    void DFS(int i, int j, vector<vector<int>> &visited, vector<vector<char>> &board) {
        // Putting node in Answer
        visited[i][j] = 1;

        // Run DFS on all non-visited neighbors
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(auto dir:directions) {
            int row = i + dir.first, col = j + dir.second;
            if(row>=0 && row<board.size() && col>=0 && col<board[0].size() && !visited[row][col] && board[row][col] == 'O') {
                DFS(row, col, visited, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        // Edge case
        if(board.empty()) return;

        vector<vector<int>> visited(board.size(), vector<int> (board[0].size(), 0));
        
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == 'O' && (i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1) && !visited[i][j]) {
                    DFS(i, j, visited, board);
                }
            }
        }
        
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }        
    }
};
// TC : O(N*M)
// SC : O(N*M)