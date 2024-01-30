#include<iostream>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> map(26,0);
        for(char ch:sentence) map[ch-'a']++;
        for(int i:map) if(i == 0) return false;
        return true; 
    }
};