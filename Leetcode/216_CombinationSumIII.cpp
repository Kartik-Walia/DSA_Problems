#include<iostream>
using namespace std;

class Solution {
public:
    void findComb(int i, int target, int arr[], vector<int> subS, vector<vector<int>> &ans, int k) {
        // Base case
        if(i == 9) {
            if(subS.size() == k && target == 0) ans.push_back(subS);
            return;
        }

        // Include 
        if(arr[i] <= target) {
            subS.push_back(arr[i]);
            findComb(i+1, target-arr[i], arr, subS, ans, k);
            subS.pop_back();
        }

        // Don't include
        findComb(i+1, target, arr, subS, ans, k);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subS;

        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        findComb(0, n, arr, subS, ans, k);

        return ans;
    }
};