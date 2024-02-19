#include<iostream>
using namespace std;


// ========================================================== Approach ==========================================================
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Edge case 
        if(n == 0) return false;

        while(n != 0) {
            if(n == 1) return true;
            if(n%2 != 0) return false;
            n /= 2;
        }
        return true;
    }
};
// TC : O(logN)
// SC : O(1)


// ==================================================== Alternative Approach ====================================================
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Edge case 
        if(n == 0) return false;

        while(n%2 == 0) n /= 2;
        return (n == 1);    // At the end 2/2 = 1
    }
};
// TC : O(logN)
// SC : O(1)