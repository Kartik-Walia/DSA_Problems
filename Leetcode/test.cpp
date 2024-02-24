#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    // Graph Implementation via Adjacency List
    vector<int> adjL[n+1];
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
     
    return 0;
}




