#include<iostream>
using namespace std;

class Solution {
public:
    void findComb(int i, int target, vector<int> &candidates, vector<int> subS, vector<vector<int>> &ans) {
        // Base case
        if(i == candidates.size()) {
            if(target == 0) ans.push_back(subS);
            return;
        }

        // Include
        if(candidates[i] <= target) {
            subS.push_back(candidates[i]);
            findComb(i, target-candidates[i], candidates, subS, ans);
            subS.pop_back();
        }

        // Don't include
        findComb(i+1, target, candidates, subS, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subS;
        vector<vector<int>> ans;

        findComb(0, target, candidates, subS, ans);

        return ans;
    }
};