#include<iostream>
#include<queue>
using namespace std;


// ALGORITHM: Start traversal from the border 1's and mark them that they can walk off, and count the remaining


// ====================================================================== Approach (BFS) ======================================================================
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), 0));
        queue<pair<int, int>> q;    // row, col

        // Initial Configuration
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(!visited[i][j] && grid[i][j] == 1 && (i==0 || i==grid.size()-1 || j==0 || j==grid[0].size()-1)) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()) {
            // Put front node into Answer
            int r = q.front().first, c = q.front().second;
            q.pop();
            visited[r][c] = 1;

            // Push all non-visited neighbours into queue
            vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
            for(auto dir:directions) {
                int row = r + dir.first, col = c + dir.second;
                if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && !visited[row][col] && grid[row][col] == 1) {
                    q.push({row, col});
                    visited[row][col] = 1;
                }
            }
        }

        int count=0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};


// ================================================================= Alternate approach (DFS) =================================================================
class Solution {
public:
    void DFS(int i, int j, vector<vector<int>> &visited, vector<vector<int>> &grid) {
        // Put node into Answer
        visited[i][j] = 1;

        // Run DFS on all non-visisted neighbours
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(auto dir:directions) {
            int row = i + dir.first, col = j + dir.second;
            if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && !visited[row][col] && grid[row][col] == 1) {
                DFS(row, col, visited, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), 0));

        // Below loop can be broken into 4 O(N) loops traversing 4 boundaries each
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(!visited[i][j] && grid[i][j] == 1 && (i==0 || i==grid.size()-1 || j==0 || j==grid[0].size()-1)) {
                    DFS(i, j, visited, grid);
                }
            }
        }

        int count=0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};