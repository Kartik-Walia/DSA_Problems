#include<iostream>
using namespace std;


// =========================================== Approach-I (Brute Force) ===========================================
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;

        // Storing all non-zero elements
        for(int i=0; i<nums.size(); i++) if(nums[i] != 0) temp.push_back(nums[i]);

        // Putting all non-zero elements in array
        for(int i=0; i<temp.size(); i++) nums[i] = temp[i];

        // Puttting zeroes in all remaining places in array
        for(int i=temp.size(); i<nums.size(); i++) nums[i] = 0;
    }
};
// TC : O(N) + O(X) + O(N-X)    [X -> no. of non-zero elements]
// SC : O(X) -> O(N)    [Array doesn't have a single zero (worst case)]


// =========================================== Approach-II (Better Approach) ===========================================
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0;

        // Move all non-zero elements to front
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) nums[k++] = nums[i];
        }

        // Put all remaining elements as zero's
        for(int i=k; i<nums.size(); i++) nums[i] = 0;
    }
};
// TC : O(N) + O(N-X)    [X -> no. of non-zero elements]
// SC : O(1)    [Not using any extra space]


// =========================================== Approach-III (Optimal Approach) ===========================================
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=-1;   // 2 pointer (j always stores indexes of 0's)

        // Edge case 
        if(nums.size() == 1) return;

        // Storing first 0th element
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                j=i;
                break;
            }
        }

        // Edge case : All elements in vector are non-zero 
        if(j == -1) return;

        // Swapping non-zero elements with 0's
        for(int i=j+1; i<nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
// TC : O(X) + O(N-X)    [X -> 1st index where 0 was found]
// SC : (1)   [Not using any extra space]