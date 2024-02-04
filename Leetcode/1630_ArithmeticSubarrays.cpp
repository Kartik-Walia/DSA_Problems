#include<iostream>
using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0; i<l.size(); i++) {
            // Making Subarray
            vector<int> comp;
            for(int j=l[i]; j<=r[i]; j++) {
                comp.push_back(nums[j]);
            }

            // Check if Subarray can be made Arithmetic or not
            sort(comp.begin(),comp.end());
            int d = comp[1] - comp[0];
            for(int k=1; k<comp.size(); k++) {
                if(comp[k] - comp[k-1] != d) {
                    ans.push_back(false);
                    break;
                }
            }
            if(ans.size() == i) ans.push_back(true);    // If false isn't pushed back
        }
        return ans;
    }
};