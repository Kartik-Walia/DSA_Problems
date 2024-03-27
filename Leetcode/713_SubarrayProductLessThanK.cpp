#include<iostream>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Edge case 
        if(k <= 1) return 0;

        int i=0, j=0, count=0, prod=1;
        while(j<nums.size()) {
            // Perform calculations
            prod *= nums[j];
            
            while(prod >= k && i<=j) {
                // Maintain condition (remove calculations of i)
                prod /= nums[i];
                i++;
            }

            count += j-i+1;     // j-i for expanded size & 1 for single subarray nums[j]
            j++;
        }

        return count;
    }
};