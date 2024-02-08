#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// ========================================== Approach-I (Brute Force) ==========================================
vector<int> rotateArray(vector<int> &arr, int n) {
    int temp = arr[0];
    for (int i = 1; i < n; i++) arr[i - 1] = arr[i];
    arr[n - 1] = temp;

    return arr;
}
// TC : O(N)
// SC : O(1) is extra space but in order to solve this problem i'm using this array, so for the algotirhm i'm using O(N) space


// ========================================== Approach-II (Optimal) ==========================================
vector<int> rotateArray(vector<int> &arr, int n) {
  reverse(arr.begin()+1, arr.end());
  reverse(arr.begin(), arr.end());

  return arr;
}