#include<iostream>
using namespace std;


class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int i = 0, j = 0;
        long sum = 0, maxSum = INT_MIN;
        
        while(j < N) {
            // Expand till we hit window size 
            if(j-i+1 < K) {
                sum += Arr[j];
                j++;
            }
            
            // Sliding window (maintain window size)
            else if (j-i+1 == K) {
                // Get answer & maintain window size
                sum += Arr[j];
                maxSum = max(maxSum, sum);
                sum -= Arr[i];

                // Slide the window
                i++; j++;
            }
        }
        
        return maxSum;
    }
};