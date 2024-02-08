#include<iostream>
using namespace std;


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0, maxC=0;
        for(int n:nums) {
            if(n == 1) {
                count++;
                maxC = max(maxC, count);
            }
            else count=0;
        }
        return maxC;
    }
};