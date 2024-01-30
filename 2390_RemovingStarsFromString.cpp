#include<iostream>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string ns = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] != '*') ns.push_back(s[i]);
            else ns.pop_back();     // Removes non-star character at left of *
        }
        return ns;
    }
};