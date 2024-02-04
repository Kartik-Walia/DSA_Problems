#include<iostream>
using namespace std;

class Solution {
public:
    int findExp(int i, int target, vector<int> &nums) {
        // Base case
        if(i == nums.size()) {
            if(target == 0) return 1;
            else return 0;
        }

        // Plus Sign
        int p = findExp(i+1, target-nums[i], nums);

        // Negative Sign
        int n = findExp(i+1, target+nums[i], nums);

        return p+n;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> arr;

        return findExp(0, target, nums);
    }
};