#include<iostream>
using namespace std;


class Solution {
public:
    bool isPalindrome(const string &s) {
        int L=0, R=s.size()-1;
        while(L <= R) {
            if(s[L] != s[R]) return false;
            L++;
            R--;
        }
        return true;
    } 

    string firstPalindrome(vector<string>& words) {
        for(const auto& s:words) {
            if(isPalindrome(s)) {
                return s;
                break;
            }
        }
        return "";
    }
};

// TC : O(M*N), where M is no.of strings & N is length of string
// SC : O(1)    [not using any additional space]