#include<iostream>
#include<queue>
using namespace std;


// ===================================================================== Approach (BFS) =====================================================================
class Graph {
public:
    bool isCyclicBFS(int i, int V, vector<int> adj[], vector<int> &visited, queue<pair<int, int>> &q) {
        // Initial configuration
        q.push({i, -1});
        visited[i] = 1;
        
        while(!q.empty()) {
            // Put front node of queue into answer
            int node = q.front().first, parent = q.front().second;
            q.pop();
            visited[node] = 1;

            // Push all non-visited neighbours of front node into queue
            for(auto it:adj[node]) {
                if(!visited[it]) {
                    q.push({it, node});
                    visited[it] = 1;
                } else if(parent != it) {
                    return true;
                }
            }
        }

        return false;
    }

    bool detectCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        queue<pair<int, int>> q;    // (node, parent)

        // Iterate over all vertices to cover case of Connected components
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(isCyclicBFS(i, V, adj, visited, q)) return true;
            }
        }

        return false;
    }
};
// TC : O(N + 2E) + O(N)
// SC : O(N) + O(N)


// ================================================================ Alternate Approach (DFS) ================================================================
class Graph {
public: 
    bool isCyclicDFS(int i, int parent, vector<int> &visited, vector<int> adj[]) {
        // Putting node into answer
        visited[i] = 1;

        // Run DFS on all non-visited neighbours
        for(auto it:adj[i]) {
            if(!visited[it]) {
                // If any of DFS calls returns a True, you keep on returning True
                if(isCyclicDFS(it, i, visited, adj)) return true;
            } else if(parent != it) {
                return true;
            }
        }

        return false;
    }

    bool detectCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);

        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(isCyclicDFS(i, -1, visited, adj)) return true;
            }
        }

        return false;
    }
};

// TC : O(N + 2E) + O(N)
// SC : O(N) + O(N)