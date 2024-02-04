#include<iostream>
using namespace std;

// ==================================================== Approach-I (Brute Force) ====================================================
// class Solution {
// public:
//     int numOfSubarrays(vector<int>& arr, int k, int threshold) {
//         int count=0;
//         for(int i=0; i<=arr.size()-k; i++) {
//             int sum=0;
//             for(int j=i; j<=i+k-1 && j<arr.size(); j++) {
//                 sum += arr[j];
//             }
//             if(sum/(double)k >= threshold) count++;
//         }
//         return count;
//     }
// };


// ==================================================== Approach-II (Sliding Window) ====================================================
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0, count=0;
        for(int i=0; i<k; i++) sum += arr[i];
        if(sum/(double)k >= threshold) count++;
        for(int i=k; i<arr.size(); i++) {
            sum -= arr[i-k];
            sum += arr[i];
            if(sum/(double)k >= threshold) count++;
        }
        return count;
    }
};