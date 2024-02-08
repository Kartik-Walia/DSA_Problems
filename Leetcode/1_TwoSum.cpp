#include<iostream>
using namespace std;


// =================================================== Approach-I (Brute Force) ===================================================
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums.size(); j++) {
                if(i == j) continue;
                if(nums[j] + nums[i] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return {};
    }
};
// TC : O(N*N)


// =================================================== Approach-II (Better Approach) ===================================================
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                if(nums[j] + nums[i] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return {};
    }
};
// TC : slightly less than O(N*N)


// =================================================== Approach-III (Optimal Approach) ===================================================
#include<map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> map;    // element, index
        for(int i=0; i<nums.size(); i++) {
            if(map.find(target-nums[i]) != map.end()) return {i, map.find(target-nums[i])->second};
            map.insert(make_pair(nums[i], i));
        }
        return {};
    }
};
// TC : O(N*logN)   [map]       [For unordered map, O(N*1) to worst case O(N*N)]
// SC : O(N)