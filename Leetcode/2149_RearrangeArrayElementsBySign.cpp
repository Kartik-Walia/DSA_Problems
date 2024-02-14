#include<iostream>
using namespace std;

// ================================================= Approach-I (Brute Force) =================================================
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p,n;
        for(int i:nums) {
            if(i>0) {
                p.push_back(i);
            } else {
                n.push_back(i);
            }
        }
        for(int i=0; i<nums.size()/2; i++) {
            nums[2*i]=p[i];    // Positive values are at even indexes
            nums[2*i + 1]=n[i];    // Negative values are at odd indexes
        }
        return nums;
    }
};
// TC : O(N) + O(N/2)
// SC : O(N/2) + O(N/2)     [p & n]


// =============================================== Approach-II (Optimal Approach) ===============================================
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0, neg=1;
        vector<int> ans(nums.size(),0);
        for(int i:nums) {
            if(i>0) {
                ans[pos] = i;
                pos += 2;
            } else {
                ans[neg] = i;
                neg += 2;
            }
        }
        return ans;
    }
};
// TC : O(N)
// SC : O(N)