#include<iostream>
using namespace std;


// ================================================================= Approach-I (Brute Force) =================================================================
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right) return left;
        int x = left;
        for(int i=left+1; i<=right; i++) x = x&i;
        return x;
    }
};
// TC : O(N)    [N is the difference between right and left]
// SC : O(1)


// =================================================================== Approach-II (Better) ===================================================================
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftCounter = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            shiftCounter++;
        }
        return left << shiftCounter;
    }
};
// TC : O(log(max(left,right)))
// SC : O(1)


// ================================================================== Approach-III (Optimal) ==================================================================
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;

        // Processing all 31 bits
        for(int i=0; i<31; i++) {
            int currNo = pow(2,i);    // BCD of that place
            if(right-left > currNo) {
                // Pigeon Hole Principle
                int to_add = 0 << i;
                ans += to_add;
            } else {
                if(left/currNo == right/currNo) {    // Belongs to Same Group
                    if(left/currNo % 2 == 0) {    // Accessing Even Group
                        int to_add = 0 << i;
                        ans += to_add;
                    } else {    // Accessing Odd Group
                        int to_add = 1 << i;
                        ans += to_add;
                    }   
                } else {    // Belongs to Different Groups
                    int to_add = 0 << i;
                    ans += to_add;
                }
            }
        }

        return ans;
    }
};
// TC : O(1)
// SC : O(1)