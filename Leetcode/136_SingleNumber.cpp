#include<iostream>
using namespace std;


// ============================================= Approach-I (Brute Force) =============================================
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            int num=nums[i], count=0;
            for(int j=0; j<nums.size(); j++) if(nums[j] == num) count++;
            if(count == 1) return num;
        }

        return -1;
    }
};
// TC : O(N*N)
// SC : O(1)


// ============================================= Approach-II (Better Approach) =============================================
#include<map>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<long long, int> cnt;
        for(int i:nums) cnt[i]++;   // Runs NlogM [M is size of map i.e. N/2 + 1]
        for(auto it:cnt) if(it.second == 1) return it.first;    // Runs for N/2 + 1

        return -1;
    }
};
// TC : O(Nlog(N/2 + 1)) + O(N/2 + 1)
// SC : O(N/2 + 1)    [using map for hashing]


// ============================================= Approach-III (Optimal Approach) =============================================
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // using XOR properties: a^a = 0 & 0^a = a
        int XOR = 0;
        for(int i:nums) XOR = XOR ^ i;
        return XOR;
    }
};
// TC : O(N)
// SC : O(1)