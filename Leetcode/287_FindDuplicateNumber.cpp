#include<iostream>
#include <unordered_set>

using namespace std;


// ======================================================================= Approach-I (Sorting) (Brute) =======================================================================
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] == nums[i+1]) return nums[i];
        }
        
        return -1;
    }
};
// TC : O(NlogN)   (Assuming merge sort)
// SC : O(1)


// ======================================================================== Approach-II (Hashing) (Better) ========================================================================
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> freq(nums.size()+1, 0);

        for(int n:nums) {
            if(freq[n]) return n;
            freq[n] = 1;
        }

        return -1;
    }
};
// TC : O(N)
// SC : O(N)


// ================================================================ Approach-III (Floyd's Cycle Detection) (Optimal) ================================================================
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        // Find collision between slow and fast pointers
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];    // Place fast pointer on 1st number

        // Move both slow and fast pointers by 1 point until the collide  
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        // Point of collision is the duplicate number
        return slow;
    }
};
// TC : O(N)
// SC : O(1)