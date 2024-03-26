#include<iostream>

using namespace std;


// ================================================================ Approach-I (Brute Force) ================================================================
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> comp;   // To store positive numbers
        unordered_map<int, int> freq;   // To avoid adding duplicates

        for(int n:nums) {
            if(n>0 && freq[n] == 0) comp.push_back(n);
            freq[n]++;
        }

        if(comp.size() == 0) return 1;      // No positive number present

        sort(comp.begin(), comp.end());
        
        // Check sequence of numbers if any one is missing return that one
        for(int i=0; i<comp.size(); i++) {
            if(comp[i] != i+1) return i+1;
        }

        return comp[comp.size()-1]+1;       // All numbers are present in correct sequence, return 1 + last one
    }
};
// TC : O(NlogN)
// SC : O(N)


// ================================================================ Approach-II (Optimal) ================================================================
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Get rid of all negative values by replacing thm with 0
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < 0) nums[i] = 0;
        }

        // Hashing the input array with itself by making values negative
        for(int i=0; i<nums.size(); i++) {
            int val = abs(nums[i]);

            // Don't check for out of bounds 
            if(val>=1 && val<=nums.size()) {
                int mappedIndex = val-1;

                // If value is positive, mark it as visited by making it negative
                if(nums[mappedIndex] > 0) {
                    nums[mappedIndex] *= -1;
                } else if (nums[mappedIndex] == 0) {    // Edge case: Value is 0 mark it as -(n+1) as it would be out of bounds
                    nums[mappedIndex] = -1 * (nums.size() + 1);
                }
            }
        }

        // Check for 1st missing positive integer
        for(int i=1; i<=nums.size(); i++) {
            int mappedIndex = i-1;

            // A positive value indicates it doesn't appeared in nums array
            if(nums[mappedIndex] >= 0) return i; 
        }

        // If all positive integers from 1 to n are present, return n+1
        return nums.size()+1;
    }
};
// TC : O(N)
// SC : O(1)