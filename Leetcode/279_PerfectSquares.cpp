#include<iostream>
using namespace std;


// =============================================== Approach-I (Brute Force - Recursion) ===============================================
class Solution {
public:
    int LeastPerfectSq(int target) {
        // Base case 
        if(target == 0) return 0;

        int minCount = INT_MAX;

        for(int i=1; i*i <= target; i++) {
            minCount = min(minCount, 1+LeastPerfectSq(target - i*i));
        }

        return minCount;
    }

    int numSquares(int n) {
        return LeastPerfectSq(n);
    }
};


// =========================================== Approach-II (Optimal Approach - Memoization) ===========================================
class Solution {
public:
    int LeastPerfectSq(int target, vector<int> &dp) {
        // Base case 
        if(target == 0) return 0;

        if(dp[target] != -1) return dp[target];

        int minCount = INT_MAX;

        for(int i=1; i*i <= target; i++) {
            minCount = min(minCount, 1+LeastPerfectSq(target - i*i, dp));
        }

        return dp[target] = minCount;
    }

    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return LeastPerfectSq(n, dp);
    }
};