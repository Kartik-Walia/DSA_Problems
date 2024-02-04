#include<iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Counting Sort 
        vector<int> cnt(3,0), ans;
        for(int i:nums) cnt[i]++;
        for(int i=0; i<=2; i++) {
            for(int j=0; j<cnt[i]; j++) {
                ans.push_back(i);
            }
        }
        nums = ans;
    }
};