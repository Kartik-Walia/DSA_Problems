#include<iostream>
using namespace std;


// ======================================================= Approach-I (Brute Force) =======================================================
class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    } 

    int countSubstrings(string s) {
        int count=0;

        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<s.size(); j++) {
                if(isPalindrome(i,j,s)) count++;
            }
        }

        return count;
    }
};