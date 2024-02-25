#include<iostream>
#include<queue>
using namespace std;


// ====================================================================== Approach-I (BFS) ======================================================================
class Solution {
  public:
    void bfs(int i, int j, queue<pair<int, int>> q, vector<vector<char>> &grid, vector<vector<int>> &visited) {
        // Initial Configuration
        q.push({i, j});
        visited[i][j] = 1;
           
        while(!q.empty()) {
            // Put front node into Answer
            pair<int, int> node = q.front();
            q.pop();
            int r = node.first, c = node.second;
            visited[r][c] = 1;
                        
            // Push all non-visited neighbours of front node into queue
            for(int row=r-1; row<=r+1; row++) {
                for(int col=c-1; col<=c+1; col++) {
                    if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && !visited[row][col] && grid[row][col] == '1') {
                        q.push({row, col});
                        visited[row][col] = 1;
                    }
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
                    bfs(i, j, q, grid, visited);
                }
            }
        }
        
        return countIsl;
    }
};
// TC : O(N^2) + O(9*(N^2)) => O(N^2)   [9 checks for neighbours]
// SC : O(N^2) + O(N^2)  [visited matrix, queue(worst case: all guys connected)]


// ====================================================================== Approach-II (DFS) ======================================================================
class Solution {
  public:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &visited) {
        // Putting node into answer
        visited[i][j] = 1;
        
        // Run DFS on all non-visited neighbours
        for(int row=i-1; row<=i+1; row++) {
            for(int col=j-1; col<=j+1; col++) {
                if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && !visited[row][col] && grid[row][col] == '1') {
                    dfs(row, col, grid, visited);
                }
            }
        }
    }
  
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), 0));
        int countIsl = 0;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    countIsl++;
                    
                    // Perform DFS
                    dfs(i, j, grid, visited);
                }
            }
        }
        
        return countIsl;
    }
};