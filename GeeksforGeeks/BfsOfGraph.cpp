#include<iostream>
#include<queue>
using namespace std;


class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        queue<int> q;
        vector<int> BFS;
        
        // Initial Configuration
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty()) {
            // Putting front node of queue to into Answer
            int node = q.front();
            q.pop();
            BFS.push_back(node);
            
            // Putting all non-visited neighbours of front node of queue into queue
            for(auto it:adj[node]) {
                if(!visited[it]) {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        
        return BFS;
    }
};