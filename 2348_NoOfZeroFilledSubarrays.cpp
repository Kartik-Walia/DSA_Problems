#include<iostream>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int consecutive = 0;

        for(int i:nums) {
            if(i == 0) consecutive++;
            else consecutive = 0;
            res += consecutive;
        }      

        return res;
    }
};