#include<iostream>
#include<queue>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // In case of multiple initial rotten oranges, we need to traverse level-wise, so we use BFS traversal for minimum time

        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), 0));
        queue<pair<pair<int, int>, int>> q;    // (row, col, time at which it get rotten)

        // Initial Configuration : Put all rotten oranges into queue
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int time = 0;
        while(!q.empty()) {
            // Put front node of queue into Answer
            pair<pair<int, int>, int> node = q.front();
            q.pop();
            int r = node.first.first, c = node.first.second, currTime = node.second;
            grid[r][c] = 2;

            // Pushing all non-visited neighbours of front node into queue
            vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
            for(auto dir:directions) {
                int row = r + dir.first, col = c + dir.second;
                if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && !visited[row][col] && grid[row][col] == 1) {
                    q.push({{row, col}, currTime + 1});
                    visited[row][col] = 1;
                }
            }

            time = max(time, currTime);
        }

        // Check for remaining fresh oranges 
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return time;
    }
};

// TC : O(N*M) + O(4*N*M) => O(N*M)
// SC : O(N*M) + O(N*M) => O(N*M)     [visited, queue]