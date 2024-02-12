#include<iostream>
using namespace std;

// =============================================== Approach-I (Brute Force) ===============================================
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};
// TC : O(NlogN)
// SC : O(N)    [Merge sortin STL uses O(N) for copying array]


// =============================================== Approach-II (Better Approach) ===============================================
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0, count1=0, count2=0;
        for(int i:nums) {
            if(i==0) count0++;
            else if(i == 1) count1++;
            else count2++;
        }
        for(int i=0; i<count0; i++) nums[i]=0;
        for(int i=count0; i<count0+count1; i++) nums[i]=1;
        for(int i=count0+count1; i<nums.size(); i++) nums[i]=2;
    }
};
// TC : O(N) + O(N)
// SC : O(1)


// =========================================== Approach-II (Optimal Approach - DNF Algorithm) ===========================================
// DNF - Dutch National Flag Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;

        // Till we have unsorted section
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else if(nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
// TC : O(N)
// SC : O(1)