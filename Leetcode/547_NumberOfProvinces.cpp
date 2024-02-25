#include<iostream>
#include<queue>
using namespace std;


// ========================================================== Approach-I (BFS) ==========================================================
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited(V,0);
        queue<int> q;
        int countComp = 0;

        // Create Adjacency List from Adjacency Matrix
        vector<int> adjL[V];
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(isConnected[i][j] && i!=j) adjL[i].push_back(j);
            }
        }

        // Loop over all nodes to cover all components of graph and run BFS on all non-visited nodes
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                // Initial Configuration
                q.push(i);
                visited[i] = 1;
                countComp++;

                while(!q.empty()) {
                    // Putting front node into Answer
                    int node = q.front();
                    q.pop();

                    // Pushing all non-visited neighbours of front node into queue
                    for(auto it:adjL[node]) {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
        }

        return countComp;
    }
};


// ========================================================== Approach-II (DFS) ==========================================================
class Solution {
public:
    void dfs(int node, vector<int> &visited, vector<int> adjL[]) {
        // Putting node into Answer
        visited[node] = 1;

        // Run dfs on all non-visited neighbours 
        for(auto it:adjL[node]) {
            if(!visited[it]) {
                dfs(it, visited, adjL);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> visited(V,0);
        int countComp = 0;

        // Create Adjacency List from Adjacency Matrix
        vector<int> adjL[V];
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(isConnected[i][j] && i!=j) adjL[i].push_back(j);
            }
        }

        // Loop over all nodes to cover all components of graph and run BFS on all non-visited nodes
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                countComp++;
                dfs(i, visited, adjL);
            }
        }

        return countComp;
    }
};
// TC : O(N) + O(V + 2E) => O(N)    [For outer loop, overall the inside loop runs for dfs times]
// SC : O(N) + O(N)     [visited, recursion stack(skewed graph)]