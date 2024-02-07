#include<iostream>
#include<set>
using namespace std;


// =========================================== Approach-I (Brute Force) ===========================================
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;    // Set stores everything in ascending order
        int i=0;

        // Set stores only unique elements
        for(int i=0; i<nums.size(); i++) st.insert(nums[i]);    // Insertion in set is O(NlogN)

        for(auto it:st) {
            nums[i] = it;
            i++;
        }

        return st.size();
    }
};
// TC : O(NlogN + N)
// SC : O(N)    [Imagine stack space in a case where whole array contains unique elements]


// =========================================== Approach-II (Optimal Approach) ===========================================
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1;   // 2 pointer
        while(j < nums.size()) {
            if(nums[j] != nums[i]) nums[++i] = nums[j];
            j++;
        }
        return i+1;    // Bcoz i refers to index
    }
};
// TC : O(N)
// SC : O(1)    [Doing in-place]