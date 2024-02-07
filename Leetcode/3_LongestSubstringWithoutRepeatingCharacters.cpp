#include<iostream>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, dupCnt=0, maxLen=0;
        unordered_map<char, int> mapN;

        while(j < s.size()) {
            // Perform calculations 
            if(mapN.find(s[j]) == mapN.end()) mapN[s[j]]++;
            else if(mapN.find(s[j]) != mapN.end()) {
                mapN[s[j]]++;
                dupCnt++;
            } 
            
            if (dupCnt == 0) {
                // Get answer from calculations 
                maxLen = max(maxLen, j-i+1);
                j++;
            }
            else if (dupCnt > 0) {
                while(dupCnt > 0) {
                    // Maintain condition (remove calculations of i)
                    mapN[s[i]]--;
                    if(mapN[s[i]] == 1) dupCnt--;
                    if(mapN[s[i]] == 0) mapN.erase(s[i]);
                    i++;
                }
                j++;
            }
        }

        return maxLen;
    }
};