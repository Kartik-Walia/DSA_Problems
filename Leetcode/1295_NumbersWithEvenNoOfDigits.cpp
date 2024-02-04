#include<iostream>
using namespace std;

class Solution {
public:
    int countDigits(int n) {
        int cnt=0;
        while(n != 0) {
            n /= 10;
            cnt++;
        }
        return (cnt % 2 == 0) ? 1 : 0;
    }

    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i:nums) count += countDigits(i);
        return count;
    }
};