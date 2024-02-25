#include<iostream>
#include<queue>
using namespace std;


// ====================================================================== Approach-I (DFS) ======================================================================
class Solution {
public:
    void DFS(int i, int j, vector<vector<int>> &image, vector<vector<int>> &visited, int initialColor, int color) {
        // Put node into Answer
        visited[i][j] = 1;
        image[i][j] = color;

        // Run DFS on all non-visited neighbours of node
        vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for(auto dir:directions) {
            int row = i + dir.first, col = j + dir.second;
            if(row>=0 && row<image.size() && col>=0 && col<image[0].size() && !visited[row][col] && image[row][col] == initialColor) {
                DFS(row, col, image, visited, initialColor, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Edge case 
        if(image[sr][sc] == color) return image;

        vector<vector<int>> visited(image.size(), vector<int> (image[0].size(), 0));
        int initialColor = image[sr][sc];

        // Perform DFS
        DFS(sr, sc, image, visited, initialColor, color);

        return image;
    }
};
// TC : O(X) + O(4*X) => O(X)    [X = N*M which is no of nodes]
// SC : O(N*M)  [Recursion Stack space]


// ====================================================================== Approach-II (BFS) ======================================================================
class Solution {
public:
    void BFS(int i, int j, queue<pair<int, int>> &q, vector<vector<int>> &visited, vector<vector<int>> &image, int initialColor, int color) {
        // Initial Configuration
        q.push({i, j});
        visited[i][j] = 1;

        while(!q.empty()) {
            // Put front node into Answer
            pair<int, int> node = q.front();
            q.pop();
            int r = node.first, c = node.second;
            image[r][c] = color;

            // Push all non-visited neighbours of front node into queue
            vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
            for(auto dir:directions) {
                int row = r + dir.first, col = c + dir.second;
                if(row>=0 && row<image.size() && col>=0 && col<image[0].size() && !visited[row][col] && image[row][col] == initialColor) {
                    q.push({row, col});
                    visited[row][col] = 1;
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Edge case 
        if(image[sr][sc] == color) return image;

        vector<vector<int>> visited(image.size(), vector<int> (image[0].size(), 0));
        queue<pair<int, int>> q;    // (row, col)
        int initialColor = image[sr][sc];

        // Perform BFS
        BFS(sr, sc, q, visited, image, initialColor, color);

        return image;
    }
};