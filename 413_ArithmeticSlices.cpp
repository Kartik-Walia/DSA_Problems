#include<iostream>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int count=0, diff;
        for(int i=0; i<nums.size()-2; i++) {
            int diff = nums[i+1] - nums[i];
            for(int j=i+2; j<nums.size(); j++) {    // i+2 bcoz we need minimum 3 elements to form AP (i, i+1 & i+2)
                if(nums[j]-nums[j-1] == diff) count++;      // [1, 2, 3] and [1, 2, 3, 4] both are considered 2 different AP's
                else break;
            }
        }
        return count;
    }
};