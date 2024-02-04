#include<iostream>
using namespace std;

// ============================================== Approach - I ==============================================
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // After nums.size() rotations array will be back to it's original
        k = k % nums.size();

        // Storing last k elements
        vector<int> temp;
        for(int i=nums.size()-k; i<nums.size(); i++) temp.push_back(nums[i]);

        // Shifting other elements to right by k steps
        for(int i=nums.size()-1; i>=k; i--) nums[i] = nums[i-k];

        // Putting back temp
        for(int i=0; i<temp.size(); i++) nums[i] = temp[i];
    }
};

// TC : O(k) + O(n-k) + O(k) = O(n+k)
// SC : O(k)



// ============================================== Approach - II ==============================================
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // After nums.size() rotations array will be back to it's original
        k = k%nums.size();

        // Reverse last k elments 
        reverse(nums.end()-k, nums.end());

        // Reverse remaining elements
        reverse(nums.begin(), nums.end()-k);

        // Reverse the whole vector
        reverse(nums.begin(), nums.end());
    }
};

// TC : O(k) + O(n-k) + O(n) = O(2n)
// SC : O(1)    (Not using any extra space)