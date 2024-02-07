#include<iostream>
using namespace std;


class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i=0, j=0, maxWs=INT_MIN;
        unordered_map<char, int> uniqCnt;   // It's size gives number of unique elements in substring
        
        while(j < s.size()) {
            // Perform calculations
            uniqCnt[s[j]]++;
            
            // Expand untill we hit window size
            if (uniqCnt.size() < k) j++;
            
            else if (uniqCnt.size() == k) {
                // Get answer from calculations
                maxWs = max(maxWs, j-i+1);
                j++;
            } 
            
            else if(uniqCnt.size() > k) {
                while(uniqCnt.size() > k) {
                    // Maintain condition (remove calculations of i)
                    uniqCnt[s[i]]--;
                    if(uniqCnt[s[i]] == 0) uniqCnt.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        
        return (maxWs == INT_MIN) ? -1 : maxWs;
    }
};