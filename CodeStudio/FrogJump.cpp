#include<iostream>
using namespace std;

// ================================================= Approach-I (Recursion) =================================================
int minEnergy(vector<int> &heights, int ind) {
    // Base case 
    if(ind == 0) return 0;

    // Edge case 
    if(ind == 1) return abs(heights[1]-heights[0]);

    int singleJump = minEnergy(heights, ind-1) + abs(heights[ind] - heights[ind-1]);
    int doubleJump = minEnergy(heights, ind-2) + abs(heights[ind] - heights[ind-2]);

    return min(singleJump, doubleJump);
}

int frogJump(int n, vector<int> &heights) {
    return minEnergy(heights, n-1);    // Min. energy required to reach from 0 to (n-1)
}
// TC : 
// SC : 


// ================================================= Approach-II (Memoization) =================================================
int minEnergy(vector<int> &heights, int ind, vector<int> &dp) {
    // Base case 
    if(ind == 0) return 0;

    // Edge case 
    if(ind == 1) return abs(heights[1]-heights[0]);

    if(dp[ind] != -1) return dp[ind];

    int singleJump = minEnergy(heights, ind-1, dp) + abs(heights[ind] - heights[ind-1]);
    int doubleJump = minEnergy(heights, ind-2, dp) + abs(heights[ind] - heights[ind-2]);

    return dp[ind] = min(singleJump, doubleJump);
}

int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n+1, -1);
    return minEnergy(heights, n-1, dp);    // Min. energy required to reach from 0 to (n-1)
}
// TC : O(N)
// SC : O(N) + O(N) [Recursion stack space & array]


// =============================================== Approach-III (Tabulation) ===============================================
int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n+1, -1);

    // Base case 
    dp[0] = 0;
    dp[1] = abs(heights[1]-heights[0]);
    
    for(int ind=2; ind<n; ind++) {
        int singleJump = dp[ind-1] + abs(heights[ind] - heights[ind-1]);
        int doubleJump = dp[ind-2] + abs(heights[ind] - heights[ind-2]);

        dp[ind] = min(singleJump, doubleJump);
    }

    return dp[n-1];
}
// TC : O(N)
// SC : O(N)    [No recursion stack space, only array space]


// =============================================== Approach-IV (Space Optimization) ===============================================
int frogJump(int n, vector<int> &heights) {
    vector<int> dp(n+1, -1);

    // Base case 
    int prev2=0, prev=abs(heights[1]-heights[0]);
    
    for(int ind=2; ind<n; ind++) {
        int singleJump = prev + abs(heights[ind] - heights[ind-1]);
        int doubleJump = prev2 + abs(heights[ind] - heights[ind-2]);

        int curi = min(singleJump, doubleJump);
        prev2 = prev;
        prev = curi;
    }

    return prev;
}
// TC : O(N)
// SC : O(1)    [No dp array & no recursion stack space]