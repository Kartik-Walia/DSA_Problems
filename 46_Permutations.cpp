#include<iostream>
using namespace std;

class Solution {
public:
    void Permutations(vector<int> &nums, vector<vector<int>> &ans, vector<int> comp, int map[]) {
        // Base Case 
        if(comp.size() == nums.size()) {
            ans.push_back(comp);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            // Checking unmarked (unpicked)
            if(!map[i]) {
                comp.push_back(nums[i]);
                map[i] = 1;     // Mark as picked
                Permutations(nums, ans, comp, map);
                comp.pop_back();
                map[i] = 0;     // Mark as unpicked
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> comp;
        int map[nums.size()];
        for(int i=0; i<nums.size(); i++) map[i] = 0;    // Initialising map with 0

        Permutations(nums, ans, comp, map);

        return ans;
    }
};