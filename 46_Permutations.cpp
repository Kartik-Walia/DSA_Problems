#include<iostream>
using namespace std;


// ============================================== Approach-I ==============================================
// class Solution {
// public:
//     void Permutations(vector<int> &nums, vector<vector<int>> &ans, vector<int> comp, int map[]) {
//         // Base Case 
//         if(comp.size() == nums.size()) {
//             ans.push_back(comp);
//             return;
//         }

//         for(int i=0; i<nums.size(); i++) {
//             // Checking unmarked (unpicked)
//             if(!map[i]) {
//                 comp.push_back(nums[i]);
//                 map[i] = 1;     // Mark as picked
//                 Permutations(nums, ans, comp, map);
//                 comp.pop_back();
//                 map[i] = 0;     // Mark as unpicked
//             }
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> comp;
//         int map[nums.size()];
//         for(int i=0; i<nums.size(); i++) map[i] = 0;    // Initialising map with 0

//         Permutations(nums, ans, comp, map);

//         return ans;
//     }
// };




// ============================================== Approach-II ==============================================
class Solution {
public:
    void Permutations(int i, vector<int> &nums, vector<vector<int>> &ans) {
        // Base case 
        if(i == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int j=i; j<nums.size(); j++) {
            swap(nums[i], nums[j]);
            Permutations(i+1, nums, ans);
            swap(nums[i], nums[j]);     // Getting back original state by re-swapping
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        Permutations(0, nums, ans);

        return ans;
    }
};