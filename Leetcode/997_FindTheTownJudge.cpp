#include<iostream>
using namespace std;


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(!trust.size() && n == 1) return 1;

        vector<int> Trust(n+1, 0);    // Trust == 0 means this node doesn't trust anyone
        vector<int> TrustedBy(n+1, 0);    // TrustedBy == 0 means this node is not trusted by anyone

        for(auto pair:trust) {
            Trust[pair[0]]++;
            TrustedBy[pair[1]]++;
        }

        for(int i=0; i<=n; i++) if(Trust[i] == 0 && TrustedBy[i] == n-1) return i;

        return -1;
    }
};
// TC : O(E+V)    [E is the number of trust relationships (edges) and V is the number of nodes (people)]
// SC : O(V)    [V is number of nodes]