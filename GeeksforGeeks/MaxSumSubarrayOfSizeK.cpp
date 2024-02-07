#include<iostream>
using namespace std;


class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int i = 0, j = 0;
        long sum = 0, maxSum = INT_MIN;
        
        while(j < N) {
            // Perform calculations
            sum += Arr[j];
            
            // Expand untill we hit window size 
            if(j-i+1 < K) j++;
            
            else if (j-i+1 == K) {
                // Get answer from calculations
                maxSum = max(maxSum, sum);
                
                // Maintain window size (remove calculations of i)
                sum -= Arr[i];
                
                // Slide window
                i++; j++;
            }
        }
        
        return maxSum;
    }
};