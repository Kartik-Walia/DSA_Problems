#include<iostream>
using namespace std;

class Solution {
public:
    bool checkPalindrome(string &s, int i, int n) {
        // Base case
        if(i >= n/2) return true;

        if(s[i] != s[n-1-i]) return false;

        swap(s[i], s[n-1-i]);
        return checkPalindrome(s, ++i, n);
    }

    bool isPalindrome(string s) {
        string ns;
        for(char c:s) {
            if(!isalnum(c)) continue;
            ns.push_back(tolower(c));
        }
        return checkPalindrome(ns, 0, ns.size());
    }
};