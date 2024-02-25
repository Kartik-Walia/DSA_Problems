#include<iostream>
#include<queue>
using namespace std;


// ====================================================================== Approach-I (DFS) ======================================================================
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>> grid) {
        // Put node into Answer
        visited[i][j] = 1;

        // Perform DFS on all non-visited neighbours of the node
        vector<pair<int , int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        for(auto dir:directions) {
            int row = i + dir.first, col = j + dir.second;
            if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && !visited[row][col] && grid[row][col] == '1') {
                dfs(row, col, visited, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), 0));
        int countIsl = 0;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    countIsl++;

                    // Perform DFS
                    dfs(i, j, visited, grid);
                }
            }
        }

        return countIsl;
    }
};


// ====================================================================== Approach-II (BFS) ======================================================================
class Solution {
public:
    void bfs(int i, int j, queue<pair<int, int>> &q, vector<vector<int>> &visited, vector<vector<char>> grid) {
        // Initial Configuration
        q.push({i, j});
        visited[i][j] = 1;

        while(!q.empty()) {
            // Put front node into the Answer
            pair<int, int> node = q.front();
            q.pop();
            int r = node.first, c = node.second;
            visited[r][c] = 1;

            // Push all non-visited neighbours of front node into queue
            vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
            for(auto dir:directions) {
                int row = r + dir.first, col = c + dir.second;
                if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && !visited[row][col] && grid[row][col] == '1') {
                    q.push({row, col});
                    visited[row][col] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), 0));
        queue<pair<int, int>> q;    // (row, col)
        int countIsl = 0;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    countIsl++;

                    // Perform BFS
                    bfs(i, j, q, visited, grid);
                }
            }
        }

        return countIsl;
    }
};