#include<iostream>
using namespace std;


// ======================================================= Approach-I (Memoization) =======================================================
class Solution {
public:
    int getMaxSum(int i, int k, vector<int> &arr, vector<int> &dp) {
        // Base case
        if(i == arr.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int maxSum = 0;
        int maxE = INT_MIN;
        for(int j=i; j<=i+k-1 && j<arr.size(); j++) {
            maxE = max(maxE, arr[j]);
            maxSum = max(maxSum, maxE*(j-i+1) + getMaxSum(j+1, k, arr, dp));
        }

        return dp[i] = maxSum; 
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return getMaxSum(0, k, arr, dp);
    }
};


// ======================================================= Approach-II (Tabulation) =======================================================
