#include<iostream>
using namespace std;

// ================================================= Approach-I (Brute Force) =================================================
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long peri=0;
        long long sum=0;
        for(int i=n-1; i>=2; i--) {
            long long longestSide = nums[i];
            sum = 0;
            for(int j=0; j<i; j++) {
                sum += nums[j];
            }
            if(longestSide < sum) return sum + longestSide;
        }

        return -1;
    }
};
// TC : O(N*N)
// SC : O(1)


// =============================================== Approach-II (Better Approach) ===============================================
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long total=0;
        vector<long long> preSum;
        for(int i:nums) {
            preSum.push_back(total);
            total += i;
        }
        for(int i=n-1; i>=2; i--) {
            long long longestSide = nums[i];
            if(longestSide < preSum[i]) return preSum[i] + longestSide;
        }

        return -1;
    }
};
// TC : O(NlogN)
// SC : O(N)    [vector preSum]


// =============================================== Approach-II (Optimal Approach) ===============================================
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long total=0;
        for(int i:nums) total += i;
        for(int i=n-1; i>=2; i--) {
            long long longestSide = nums[i];
            total -= longestSide;
            if(longestSide < total) return total + longestSide;
        }

        return -1;
    }
};
// TC : O(NlogN)
// SC : O(1)