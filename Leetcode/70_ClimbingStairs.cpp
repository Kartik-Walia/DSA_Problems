#include<iostream>
using namespace std;


// ================================================ Approach-I (Recursion) ================================================
class Solution {
public:
    int ways(int ind) {
        // Base case 
        if(ind == 0) return 1;  // To count all possible ways we return 1 at base case

        // Edge case 
        if(ind == 1) return 1;

        int oneStep = ways(ind-1);
        int twoStep = ways(ind-2);

        return (oneStep + twoStep);
    }

    int climbStairs(int n) {
        return ways(n);
    }
};


// =============================================== Approach-II (Memoization) ===============================================
class Solution {
public:
    int ways(int n, vector<int> &dp) {
        // Base case 
        if(n == 0) return 1;

        // Edge case 
        if(n == 1) return 1;

        int oneStep = (dp[n-1] != -1) ? dp[n-1] : ways(n-1, dp); 
        int twoStep = (dp[n-2] != -1) ? dp[n-2] : ways(n-2, dp);

        return dp[n] = (oneStep + twoStep); 
    }

    int climbStairs(int n) {
        vector<int> dp(100,-1);
        return ways(n, dp);
    }
};


// =============================================== Approach-III (Tabulation) ===============================================
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(100, -1);
        dp[0]=1, dp[1]=1;

        // Base case 
        if(n == 0) return dp[0];
        if(n == 1) return dp[1];
        
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};


// ============================================ Approach-IV (Space Optimization) ============================================
class Solution {
public:
    int climbStairs(int n) {
        int prev2=1, prev=1;
        for(int i=2; i<=n; i++) {
            int curi = prev + prev2;
            prev2 = prev;
            prev = curi;
        }
        
        return prev;
    }
};