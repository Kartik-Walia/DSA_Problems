#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size(), i = 0;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        while(i <= n-3) {
            if(nums[i+2]-nums[i] <= k) ans.push_back({nums[i], nums[i+1], nums[i+2]});
            else return {};
            i += 3;
        }
        return ans;
    }
};