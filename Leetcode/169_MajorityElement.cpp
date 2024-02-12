#include<iostream>
using namespace std;

// ================================================= Approach-I (Brute Force) =================================================
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            int count=0;
            for(int j=0; j<nums.size(); j++) {
                if(nums[j] == nums[i]) count++;
            }
            if(count > nums.size()/2) return nums[i];
        }
        return -1;
    }
};
// TC : O(N*N)


// =============================================== Approach-II (Better Approach) ===============================================
#include<map>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> cnt;    // element, count
        for(int i:nums) cnt[i]++;   // NlogN    [if use unordered map, then this logN will go of only in avg and best case, if worst case unordered map takes O(N) time within itself]
        for(auto it:cnt) if(it.second > nums.size()/2) return it.first;     // O(N)
        return -1;
    }
};
// TC : O(NlogN) + O(N)
// SC : O(N)    [Array contains all unique elements]


// ========================================= Approach-II (Optimal Approach - BMMV Algorithm) =========================================
// BMMV - Boyer-Moore Majority Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele, count=0;
        for(int i:nums) {
            if(count == 0) {
                count=1;
                ele=i;
            } 
            else if(i == ele) count++;
            else count--;
        }

        // Not needed if there's surity that ,majority element exists
        int cnt=0;
        for(int i:nums) if(i == ele) cnt++;
        if(cnt > nums.size()/2) return ele;
        return -1;
    }
};
// TC : O(N) + O(N) [2nd O(N) if there's no surity that majority element exists, if it's sure majority element exists no need of 2nd step]
// SC : O(1)