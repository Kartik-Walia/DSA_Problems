#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long int res=0;
        while(x != 0) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res >= -pow(2,31) && res <= pow(2,31)-1) ? res : 0;
    }
};