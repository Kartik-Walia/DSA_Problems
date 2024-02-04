#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs;
        sort(potions.begin(),potions.end());

        for(int s:spells) {
            // Binary Search 
            int L=0, R=potions.size()-1;
            int index = potions.size();  // Used for finding Left most value in potions that satisfies condition
            while(L <= R) {
                int mid = L + (R-L)/2;
                if((long long)s*potions[mid] >= success) {
                    R = mid-1;
                    index = mid;    // Store leftmost value in potions that satisfies condition
                } else {
                    L = mid+1;
                }
            }
            // All elements except elements at left of leftmost (index) would satisfy as we earlier sorted potions vector
            pairs.push_back(potions.size()-index);  // To prevent out of bound, initialise index with potions.size() instead of 0
        }

        return pairs;
    }
};