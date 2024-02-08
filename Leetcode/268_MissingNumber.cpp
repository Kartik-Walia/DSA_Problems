#include<iostream>
using namespace std;


// ====================================================== Approach-I (Brute force) ======================================================
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i=0; i<=nums.size(); i++) {
            int flag = 0;
            for(int j=0; j<nums.size(); j++) {
                if(nums[j] == i) flag = 1;
            }
            if(flag == 0) return i;
        }

        return -1;
    }
};
// TC : O(N*N)
// SC : O(1)


// ==================================================== Approach-II (Better Approach) ====================================================
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> visited(nums.size()+1,0);   // For hashing visited values
        for(int i:nums) visited[i]=1;
        for(int i=0; i<visited.size(); i++) if(visited[i] == 0) return i;
        return -1; 
    }
};
// TC : O(N) + O(N)
// SC : O(N)    [using vector visited for hashing]


// ================================================ Approach-III (Optimal Approach - Sum) ================================================
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = (nums.size()*(nums.size()+1))/2;
        int s=0;

        // Using difference of sum & s to find out missing number
        for(int i:nums) s += i;

        return (sum-s > 0) ? sum-s : 0;
    }
};
// TC : O(N)
// SC : O(1)


// ================================================ Approach-IV (Legend Approach - XOR) ================================================
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // using XOR properties: a^a = 0 & 0^a = a
        int XOR_1 = 0, XOR_2 = 0;   // XOR_1 is for indexes & XOR_2 is for missing number
        for(int i=0; i<nums.size(); i++) {
            XOR_1 = XOR_1 ^ i;
            XOR_2 = XOR_2 ^ nums[i];
        }
        XOR_1 = XOR_1 ^ nums.size();    // n haven't been included bcoz 1 element is missing (0 -> n-1)
        
        return XOR_1 ^ XOR_2;
    }
};
// EXPLANATION:
// XOR_1 = 0^1^2^3^4
// XOR_2 = 0^1^2^4
// XOR_1 ^ XOR_2 = (0^0)^(1^1)^(2^2)^(3)^(4^4) = 0^0^0^3^0 = 0^3 = 3

// TC : O(N)
// SC : O(1)


// XOR is better than Sum 
// Bcoz imagine N=pow(10,5) now (N*(N+1))/2 would go out of integer range (around pow(10,10)) which needs bigger datatype as long which would result in a slight increase of memory where as XOR would never exceed largest number it would at max give pow(10,5)
// Hence in SC terms XOR is slightly better for larger N values