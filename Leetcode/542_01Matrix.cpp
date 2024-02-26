#include<iostream>
#include<queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // Multi-Source BFS (nearest) (never hamper data given to us)
        vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(),0));
        vector<vector<int>> distance(mat.size(), vector<int>(mat[0].size(),0));     // Store distance to nearest 0's for every particular cell
        queue<pair<pair<int, int>, int>> q;     // (row, col, steps)

        // Initial Configuration
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});    // Nearest 0 from 0 is at 0 steps
                    visited[i][j] = 1;
                }
            }
        }

        while(!q.empty()) {
            // Put front node of queue into Answer
            int r = q.front().first.first, c = q.front().first.second, steps = q.front().second;
            q.pop();
            distance[r][c] = steps;

            // Push all non-visited neighbors of front node into the queue
            vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
            for(auto dir:directions) {
                int row = r + dir.first, col = c + dir.second;
                if(row>=0 && row<mat.size() && col>=0 && col<mat[0].size() && !visited[row][col]) {
                    q.push({{row, col}, steps + 1});
                    visited[row][col] = 1;
                }
            }
        }

        return distance;
    }
};
// TC : O(N*M) + O(4*N*M) => O(N*M)
// SC : O(N*M) + O(N*M) + O(N*M) => O(N*M)      [visited, distance, queue]