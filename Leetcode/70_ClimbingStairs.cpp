#include<iostream>
using namespace std;


// =============================================== Approach-I (Memoization) ===============================================
// class Solution {
// public:
//     int ways(int n, vector<int> &dp) {
//         // Base case 
//         if(n == 0) return 1;

//         // Edge case 
//         if(n == 1) return 1;

//         int oneStep = (dp[n-1] != -1) ? dp[n-1] : ways(n-1, dp); 
//         int twoStep = (dp[n-2] != -1) ? dp[n-2] : ways(n-2, dp);

//         return dp[n] = (oneStep + twoStep); 
//     }

//     int climbStairs(int n) {
//         vector<int> dp(100,-1);
//         return ways(n, dp);
//     }
// };


// =============================================== Approach-II (Tabulation) ===============================================
// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp(100, -1);
//         dp[0]=1, dp[1]=1;

//         // Base case 
//         if(n == 0) return dp[0];
//         if(n == 1) return dp[1];
        
//         for(int i=2; i<=n; i++) {
//             dp[i] = dp[i-1] + dp[i-2];
//         }

//         return dp[n];
//     }
// };


// ============================================ Approach-III (Space Optimization) ============================================
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