#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1; i<=9; i++) {
            int j=i, n=i;
            while(n <= high && j<=9) {
                if(n>=low && n<=high) ans.push_back(n);
                n = (n*10)+(++j);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};