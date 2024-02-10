#include<iostream>
using namespace std;


// ====================================================== Approach-I (Brute Force) ======================================================
class Solution {
public:
    bool isValidCandidate(vector<int> comp) {
        for(int i=0; i<comp.size(); i++) {
            for(int j=i+1; j<comp.size(); j++) {
                if(comp[i]%comp[j] != 0 && comp[j]%comp[i] != 0) return false;
            }
        }
        return true;
    }

    void subSets(int index, vector<int> &nums, vector<int> &comp, vector<vector<int>> &ans){
        // Base case 
        if(index >= nums.size()) { 
            if(isValidCandidate(comp) && comp.size() != 0) ans.push_back(comp);
            return;
        }

        // Include 
        comp.push_back(nums[index]);
        subSets(index+1, nums, comp, ans);
        comp.pop_back();

        // Don't include
        subSets(index+1, nums, comp, ans);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> comp;
        vector<vector<int>> ans;

        subSets(0, nums, comp, ans);

        vector<pair<vector<int>, int>> pair;    // subset, size
        for(auto it:ans) {
            pair.push_back(make_pair(it, it.size()));
        }

        int maxSize = INT_MIN;
        for(auto it:pair) {
            maxSize = max(maxSize, it.second);
        }

        for(auto it:pair) if(it.second == maxSize) return it.first;

        return {};
    }
};


// =================================================== Approach-II (Optimal Approach) ===================================================
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Traversing Right to Left
        vector<int> ans;
        unordered_map<int, vector<int>> dp;     // element, largest possible subset with element as head
        int n = nums.size();

        sort(nums.begin(), nums.end());

        // Manual calculation for last element 
        dp[nums[n-1]].push_back(nums[n-1]);
        ans = dp[nums[n-1]];

        // Iteratively calculating for rest 
        for(int i=n-2; i>=0; i--) {
            int head = nums[i];
            dp[head].push_back(head);
            for(int j=i+1; j<n; j++) {
                // Can extend ?
                if(nums[j]%head == 0) {
                    // Should i extend or not ?
                    if(dp[head].size() < dp[nums[j]].size() + 1) {
                        dp[head] = dp[nums[j]];
                        dp[head].push_back(head);
                    }
                }

            }

            if(dp[head].size() > ans.size()) ans = dp[head];
        }

        return ans;
    }
};