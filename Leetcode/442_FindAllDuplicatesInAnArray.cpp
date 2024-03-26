#include<iostream>

using namespace std;


// ================================================================ Approach-I (Brute Force) ================================================================
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans, freq(nums.size()+1, 0);
        
        for (int j=0; j<nums.size(); j++) freq[nums[j]]++;

        for (int k=0; k<freq.size(); k++) {
            if (freq[k] == 2) ans.push_back(k);
        }
        
        return ans;
    }
};
// TC : O(N)
// SC : O(N)


// ================================================================ Approach-II (Optimal) ================================================================
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(int i=0; i<nums.size(); i++) {
            // Adjust indexing to be 0-based (So that n can also be covered)
            int index = abs(nums[i]) - 1;

            // If visited, return duplicate
            if(nums[index] < 0) {
                ans.push_back(index+1);
            } else {
                nums[index] = -nums[index];    // Mark visited
            }
        }
        
        return ans;
    }
};
// TC : O(N)
// SC : O(1)