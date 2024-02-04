#include<iostream>
using namespace std;

#include<cmath>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        }
        int y = x;
        long int reverse = 0;
        while(y != 0) {
            reverse = (reverse*10) + (y%10);
            y = y/10;
        }
        if(reverse == x) {
            return true;
        } else {
            return false;
        }
    }
};