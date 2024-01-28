#include<iostream>
using namespace std;

class Solution {
public:
    void subSet(int i, vector<int> &nums, vector<int> &subS, vector<vector<int>> &ans) {
        ans.push_back(subS);

        for(int j=i; j<nums.size(); j++) {
            if(j>i && nums[j] == nums[j-1]) continue;
            subS.push_back(nums[j]);
            subSet(j+1, nums, subS, ans);
            subS.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> subS;

        subSet(0, nums, subS, ans);

        return ans;
    }
};