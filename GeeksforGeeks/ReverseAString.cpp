#include<iostream>
using namespace std;


class Solution
{
    public:
    string reverseWord(string str)
    {
        int l=0, r=str.size()-1;
        while(l <= r) {
            swap(str[l], str[r]);
            l++; r--;
        }
        
        return str;
    }
};