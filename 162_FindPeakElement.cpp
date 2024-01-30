#include<iostream>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int L = 0, R = nums.size()-1, mid=0;
        while(L <= R) {
            mid = L + ((R-L)/2);
            
            // Search on the side where neighbour value is greater than mid value 
            if(mid>0 && nums[mid-1]>nums[mid]) R = mid-1;   // Left neighbour greater
            else if(mid<nums.size()-1 && nums[mid+1]>nums[mid]) L = mid+1;  // Right neighbour greater
            else break;
        }
        return mid;
    }
};