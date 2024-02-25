#include<iostream>
using namespace std;


class Solution {
  public:
    void dfs(int node, vector<int> &DFS, vector<int> &visited, vector<int> adj[]) {
        // Putting node in Answer
        DFS.push_back(node);
        visited[node] = 1;
        
        // Run dfs on all non-visited neighbours
        for(auto it:adj[node]) {
            if(!visited[it]) {
                dfs(it, DFS, visited, adj);
            }
        }
    }
  
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> DFS;
        
        // Call recursive dfs function from starting node
        dfs(0, DFS, visited, adj);
        
        return DFS;
    }
};