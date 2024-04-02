#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mpST, mpTS;
        for(int i=0; i<s.length(); i++){
            if(mpST[s[i]] && mpST[s[i]]!=t[i]) return false;
            if(mpTS[t[i]] && mpTS[t[i]]!=s[i]) return false;
            mpST[s[i]] = t[i];
            mpTS[t[i]] = s[i];
        }
        return true;
    }
};