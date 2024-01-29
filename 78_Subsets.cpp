#include<iostream>
using namespace std;

class Solution {
public:
    void findsubS(int i, vector<int> &nums, vector<int> &subS, vector<vector<int>> &ans) {
        // Base case 
        if(i == nums.size()) {
            ans.push_back(subS);
            return;
        }

        // Include
        subS.push_back(nums[i]);
        findsubS(i+1, nums, subS, ans);
        subS.pop_back();

        // Don't include
        findsubS(i+1, nums, subS, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subS;

        findsubS(0, nums, subS, ans);

        return ans;
    }
};