#include<iostream>

using namespace std;

vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    int i = 0, j = 0;
    long long sum = 0;
    vector<vector<int>> ans;

    while (j < a.size()) {
        // Perform calculations
        sum += a[j];

        // Expand the window until we hit the array boundary
        if (sum < k) {
            j++;
        } else {
            while (sum > k && i <= j) {
                // Shrink the window until sum <= k
                sum -= a[i];
                i++;
            }
            if (sum == k) {
                // Get answer from calculations
                vector<int> comp(a.begin() + i, a.begin() + j + 1);
                ans.push_back(comp);

                // Clear comp for the next subarray
                comp.clear();
            }
            j++;
        }
    }

    return ans;
}
